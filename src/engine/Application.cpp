#include "headers.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace Engine
{
  Application *Application::s_Instance = nullptr;

  Application::Application()
  {
    s_Instance = this;

    m_Window = SDLWindow::Create();
    m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

    m_ImGuiLayer = new ImGuiLayer();
    PushOverlay(m_ImGuiLayer);
  }
  Application::~Application() {}

  void Application::PushLayer(Layer *layer)
  {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
  };

  void Application::PushOverlay(Layer *layer)
  {
    m_LayerStack.PushOverlay(layer);
    layer->OnAttach();
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

      m_ImGuiLayer->NewFrame();
      {
        for (Layer *layer : m_LayerStack)
          layer->OnImGuiRender();
      }
      m_ImGuiLayer->Render();

      m_Window->OnUpdate();
      m_Window->HandleEvents();
    }
  }
}