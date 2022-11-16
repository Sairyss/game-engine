#include "headers.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace Engine
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

  Application::Application()
  {
    m_Window = SDLWindow::Create();
    m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
  }
  Application::~Application() {}

  void Application::PushLayer(Layer *layer)
  {
    m_LayerStack.PushLayer(layer);
  };

  void Application::PushOverlay(Layer *layer)
  {
    m_LayerStack.PushOverlay(layer);
  };

  void Application::OnEvent(Event &e)
  {
    LOG_CORE_DEBUG("[Event] {0}", e.ToString());

    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
    {
      if (e.Handled)
        break;
      (*it)->OnEvent(e);
    }
  };

  bool Application::OnWindowClose(WindowCloseEvent &e)
  {
    m_Running = false;
    return true;
  };

  void Application::Run()
  {
    while (m_Running)
    {
      Timestep *ts = new Timestep();
      for (Layer *layer : m_LayerStack)
        layer->OnUpdate(*ts);

      m_Window->OnUpdate();
      m_Window->HandleEvents();
    }
  }
}