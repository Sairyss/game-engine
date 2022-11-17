#include "../../headers.h"
#include "../../Core/Input.h"

#include "../../Application.h"
#include <SDL2/SDL.h>

// Input polling

namespace Engine
{

	bool Input::IsKeyPressed(const KeyCode key)
	{
		auto *window = static_cast<SDL_Window *>(Application::Get().GetWindow().GetNativeWindow());
		const Uint8 *state = SDL_GetKeyboardState(nullptr);
		return state[key];
	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		auto *window = static_cast<SDL_Window *>(Application::Get().GetWindow().GetNativeWindow());
		int x, y;
		Uint32 state;
		state = SDL_GetMouseState(&x, &y);
		return state && state == button;
	}

	glm::vec2 Input::GetMousePosition()
	{
		auto *window = static_cast<SDL_Window *>(Application::Get().GetWindow().GetNativeWindow());
		int xPos, yPos;
		const Uint32 state = SDL_GetMouseState(&xPos, &yPos);
		return {(float)xPos, (float)yPos};
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}

}