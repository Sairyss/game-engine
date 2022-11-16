#include "headers.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace Engine
{

  Application::Application()
  {
    m_Window = SDLWindow::Create();
  }
  Application::~Application() {}

  void Application::Run()
  {
    WindowResizeEvent e(1280, 720);
    LOG_TRACE(e.ToString());

    while (m_Running)
    {
      m_Window->OnUpdate();
    }
  }
}