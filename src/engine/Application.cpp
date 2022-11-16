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

  void Application::OnEvent(Event &e)
  {
    LOG_CORE_DEBUG("[Event] {0}", e.ToString());

    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
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
      m_Window->OnUpdate();
      m_Window->HandleEvents();
    }
  }
}