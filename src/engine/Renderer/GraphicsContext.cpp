#include "../headers.h"
#include "GraphicsContext.h"

// #include "Renderer.h"
#include "../Platform/OpenGL/OpenGLContext.h"
#include "RendererAPI.h"

namespace Engine
{

	GraphicsContext *GraphicsContext::Create(void *window, int width, int height)
	{
		switch ((Engine::RendererAPI::API)1) // Renderer::GetAPI() // TODO
		{
		case RendererAPI::API::None:
			// CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLContext(static_cast<SDL_Window *>(window), height, width);
		}

		// CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}