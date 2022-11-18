#pragma once

namespace Engine
{

	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;
		static GraphicsContext *Create(void *window, int width, int height);

		virtual void *GetNativeContext() const { return m_Context; }

		virtual void Init() = 0;
		virtual void SwapWindow() = 0;

	private:
		void *m_Context;
	};

}