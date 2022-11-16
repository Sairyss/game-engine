#pragma once

#include "Window.h"
#include <SDL2/SDL.h>

namespace Engine
{

  class SDLWindow : public Window
  {
  public:
    SDLWindow(const WindowProps &props);
    virtual ~SDLWindow();

    void OnUpdate() override;
    void HandleEvents() override;

    static Window *Create(const WindowProps &props = WindowProps());

    unsigned int GetWidth() const override { return m_Data.Width; }
    unsigned int GetHeight() const override { return m_Data.Height; }

    // Window attributes
    void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;

    virtual void *GetNativeWindow() const { return m_Window; }

  private:
    virtual void Init(const WindowProps &props);
    virtual void Shutdown();

  private:
    SDL_Window *m_Window;
    static SDL_Renderer *m_Renderer;
    static SDL_Event event;

    struct WindowData
    {
      std::string Title;
      unsigned int Width, Height;
      bool VSync;

      EventCallbackFn EventCallback;
    };

    WindowData m_Data;
  };

}