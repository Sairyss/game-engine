#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Core/Log.h"

namespace Engine
{
  Application::Application() {}
  Application::~Application() {}

  void Application::Run()
  {
    WindowResizeEvent e(1280, 720);
    LOG_TRACE(e.ToString());

    while (true)
    {
    }
  }
}