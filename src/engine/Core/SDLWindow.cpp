#include "headers.h"
#include "SDLWindow.h"

#include "../Events/ApplicationEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"
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
    // HZ_PROFILE_FUNCTION();

    Init(props);
  }

  SDLWindow::~SDLWindow()
  {
    // HZ_PROFILE_FUNCTION();

    Shutdown();
  }

  void SDLWindow::Init(const WindowProps &props)
  {
    // HZ_PROFILE_FUNCTION();

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

    SDL_GLContext m_Context = SDL_GL_CreateContext(m_Window);

    // m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

    // if (m_Renderer == NULL)
    // {
    //   {
    //     LOG_CORE_ERROR("SDL Could not create renderer: {0}", SDL_GetError());
    //     return;
    //   }
    // }
    // SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

    gladLoadGL();

    glViewport(0, 0, GetWidth(), GetHeight());
    glClearColor(1.f, 0.f, 1.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    LOG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
  }

  void SDLWindow::Shutdown()
  {
    // HZ_PROFILE_FUNCTION();

    SDL_GL_DeleteContext(m_Context);
    SDL_DestroyWindow(m_Window);
    // SDL_DestroyRenderer(m_Renderer);
    SDL_Quit();
  }

  void SDLWindow::OnUpdate()
  {
    // HZ_PROFILE_FUNCTION();

    SDL_GL_SwapWindow(m_Window);
  }

  void SDLWindow::HandleEvents()
  {
    // HZ_PROFILE_FUNCTION();

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
      KeyPressedEvent e(m_Event.key.keysym.sym);
      m_Data.EventCallback(e);
    }

    if (m_Event.type == SDL_KEYUP)
    {
      KeyReleasedEvent e(m_Event.key.keysym.sym);
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
    // HZ_PROFILE_FUNCTION();

    m_Data.VSync = enabled;
  }

  bool SDLWindow::IsVSync() const
  {
    return m_Data.VSync;
  }
}