#include "../../headers.h"
#include "SDLWindow.h"

#include "../../Events/ApplicationEvent.h"
#include "../../Events/MouseEvent.h"
#include "../../Events/KeyEvent.h"
#include <glad/glad.h>

namespace Engine
{

  SDL_Event SDLWindow::m_Event;

  Window *SDLWindow::Create(const WindowProps &props)
  {
    return new SDLWindow(props);
  }

  SDLWindow::SDLWindow(const WindowProps &props)
  {
    // PROFILE_FUNCTION();

    Init(props);
  }

  SDLWindow::~SDLWindow()
  {
    // PROFILE_FUNCTION();

    Shutdown();
  }

  void SDLWindow::Init(const WindowProps &props)
  {
    // PROFILE_FUNCTION();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
      LOG_CORE_ERROR("SDL Could not init: {0}", SDL_GetError());
      return;
    }

    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    Uint32 WindowFlags = SDL_WINDOW_OPENGL;

    m_Window = SDL_CreateWindow(
        m_Data.Title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_Data.Width,
        m_Data.Height,
        WindowFlags);

    if (m_Window == NULL)
    {
      LOG_CORE_ERROR("SDL Could not create window: {0}", SDL_GetError());
      return;
    };

    m_Context = GraphicsContext::Create(m_Window, GetWidth(), GetHeight());
    m_Context->Init();

    LOG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
  }

  void SDLWindow::Shutdown()
  {
    // PROFILE_FUNCTION();

    SDL_GL_DeleteContext(m_Context);
    SDL_DestroyWindow(m_Window);
    // SDL_DestroyRenderer(m_Renderer);
    SDL_Quit();
  }

  void SDLWindow::OnUpdate()
  {
    // PROFILE_FUNCTION();

    m_Context->SwapWindow();
    HandleEvents();
  }

  void SDLWindow::HandleEvents()
  {
    // PROFILE_FUNCTION();

    SDL_PollEvent(&m_Event);

    if (m_Event.type == SDL_KEYDOWN)
    {
      switch (m_Event.key.keysym.sym)
      {
      case SDLK_ESCAPE:
      {
        WindowCloseEvent e;
        m_Data.EventCallback(e);
        break;
      }

      default:
        break;
      }
    }

    if (m_Event.type == SDL_KEYDOWN)
    {
      KeyPressedEvent e(m_Event.key.keysym.scancode);
      m_Data.EventCallback(e);
    }

    if (m_Event.type == SDL_KEYUP)
    {
      KeyReleasedEvent e(m_Event.key.keysym.scancode);
      m_Data.EventCallback(e);
    }

    if (m_Event.type == SDL_MOUSEBUTTONDOWN)
    {
      MouseButtonPressedEvent e(m_Event.button.button);
      m_Data.EventCallback(e);
    }

    if (m_Event.type == SDL_MOUSEBUTTONUP)
    {
      MouseButtonReleasedEvent e(m_Event.button.button);
      m_Data.EventCallback(e);
    }

    if (m_Event.type == SDL_MOUSEMOTION)
    {
      MouseMovedEvent e(m_Event.button.x, m_Event.button.y);
      m_Data.EventCallback(e);
    }
  }

  void SDLWindow::SetVSync(bool enabled)
  {
    // PROFILE_FUNCTION();

    m_Data.VSync = enabled;
  }

  bool SDLWindow::IsVSync() const
  {
    return m_Data.VSync;
  }
}