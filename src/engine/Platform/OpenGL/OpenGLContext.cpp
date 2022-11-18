#include "../../headers.h"
#include "OpenGLContext.h"

namespace Engine
{
	GraphicsContext *OpenGLContext::Create(SDL_Window *window, int width, int height)
	{
		return new OpenGLContext(window, width, height);
	};

	OpenGLContext::OpenGLContext(SDL_Window *window, int width, int height)

	{
		// CORE_ASSERT(window, "Window is null!")
		m_Window = window;
		m_Width = width;
		m_Height = height;
	}

	void OpenGLContext::Init()
	{
		// PROFILE_FUNCTION();

		SDL_GLContext m_Context = SDL_GL_CreateContext(m_Window);

		gladLoadGL();

		glViewport(0, 0, m_Width, m_Height);
		glClearColor(1.f, 0.f, 1.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		LOG_CORE_INFO("OpenGL Info:");
		// LOG_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		// LOG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		// LOG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		// CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Engine requires at least OpenGL version 4.5");
	}

	void OpenGLContext::SwapWindow()
	{
		// PROFILE_FUNCTION();

		SDL_GL_SwapWindow(m_Window);
	}

}
