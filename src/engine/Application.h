#pragma once

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Core/SDLWindow.h"

namespace Engine
{
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event &e);
    bool OnWindowClose(WindowCloseEvent &e);

    Window *m_Window;

  private:
    bool m_Running = true;
  };
}