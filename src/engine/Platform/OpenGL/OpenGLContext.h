#pragma once

#include "../../Renderer/GraphicsContext.h"
#include <SDL2/SDL.h>
#include <glad/glad.h>

namespace Engine
{

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(SDL_Window *window, int width, int height);
		static GraphicsContext *Create(SDL_Window *window, int width, int height);

		virtual void Init() override;
		virtual void SwapWindow() override;

	private:
		SDL_Window *m_Window;
		SDL_GLContext m_Context;

		int m_Width, m_Height;
	};

}