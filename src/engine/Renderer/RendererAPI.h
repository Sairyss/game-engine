#pragma once

#include <glm/glm.hpp>

namespace Engine
{

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

	public:
		virtual ~RendererAPI() = default;

		static API GetAPI() { return s_API; }
		static RendererAPI *Create();

	private:
		static API s_API;
	};

}
