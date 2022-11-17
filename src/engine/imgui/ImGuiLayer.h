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

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    // void OnEvent(Engine::Event &e);
    virtual void OnImGuiRender() override;
    virtual void NewFrame();
    virtual void Render();

  private:
    float m_Time = 0.0f;
  };
}