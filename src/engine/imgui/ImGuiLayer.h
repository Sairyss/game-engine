#pragma once

#include "../Core/Layer.h"
#include "../Core/Log.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"

namespace Engine
{
  class ImGuiLayer : public Layer
  {
  public:
    ImGuiLayer();
    ~ImGuiLayer();

    void OnAttach();
    void OnDetach();
    void OnUpdate(Engine::Timestep ts);
    // void OnEvent(Engine::Event &e);

  private:
    float m_Time = 0.0f;
  };
}