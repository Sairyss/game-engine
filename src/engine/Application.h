#pragma once

#include "Events/Event.h"
#include "Core/SDLWindow.h"

namespace Engine
{
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    Window *m_Window;

  private:
    bool m_Running = true;
  };
}