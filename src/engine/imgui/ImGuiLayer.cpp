#include "../headers.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "../Platform/OpenGL/ImguiOpenGLRenderer.h"
#include "../Application.h"
#include <backends/imgui_impl_sdl.h>
#include <glad/glad.h>

namespace Engine
{
  ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer"){};
  ImGuiLayer::~ImGuiLayer(){};

  void ImGuiLayer::OnAttach()
  {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO &io = ImGui::GetIO();

    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    Application &app = Application::Get();
    SDL_Window *window = static_cast<SDL_Window *>(app.GetWindow().GetNativeWindow());
    SDL_GLContext *context = static_cast<SDL_GLContext *>(app.GetWindow().GetNativeContext());

    ImGui_ImplSDL2_InitForOpenGL(window, context);

    ImGui_ImplOpenGL3_Init("#version 410");
  };

  void ImGuiLayer::OnDetach()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
  };

  void ImGuiLayer::OnUpdate(Engine::Timestep ts)
  {
    ImGuiIO &io = ImGui::GetIO();
    Application &app = Application::Get();
    Window &window = app.GetWindow();
    io.DisplaySize = ImVec2((float)window.GetWidth(), (float)app.GetWindow().GetHeight());

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_Event *event = static_cast<SDL_Event *>(window.GetNativeEvent());
    ImGui_ImplSDL2_ProcessEvent(event);
  }

  // void ImGuiLayer::OnEvent(Engine::Event &event)
  // {
  //   LOG_CORE_DEBUG("[ImGui Layer] {0}", event.ToString());
  // }

}