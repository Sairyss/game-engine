#pragma once

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Platform/SDL/SDLWindow.h"
#include "Core/LayerStack.h"
#include "Core/Timestep.h"
#include "imgui/ImGuiLayer.h"

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

    static Application &Get() { return *s_Instance; }
    inline Window &GetWindow() { return *m_Window; }

  private:
    Window *m_Window;
    bool m_Running = true;
    bool OnWindowClose(WindowCloseEvent &e);
    ImGuiLayer *m_ImGuiLayer;
    static Application *s_Instance;

    LayerStack m_LayerStack;
  };
}