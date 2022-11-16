#pragma once

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Core/SDLWindow.h"
#include "Core/LayerStack.h"
#include "Core/Timestep.h"

namespace Engine
{
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event &e);

    void PushLayer(Layer *layer);
    void PushOverlay(Layer *layer);

  private:
    Window *m_Window;
    bool m_Running = true;
    bool OnWindowClose(WindowCloseEvent &e);

    LayerStack m_LayerStack;
  };
}