cmake_minimum_required(VERSION 3.0.0)
project(game-engine VERSION 0.1.0)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

add_executable(
game-engine 
src/main.cpp 
src/sandbox/Sandbox.cpp 
src/engine/Application.cpp 
src/engine/Core/Log.cpp 
src/engine/headers.cpp 
src/engine/Platform/SDL/SDLWindow.cpp
src/engine/Core/LayerStack.cpp
src/engine/Core/Layer.cpp
src/engine/imgui/ImGuiLayer.cpp
src/engine/Platform/OpenGL/ImguiOpenGLRenderer.cpp
src/engine/Platform/SDL/SDLInput.cpp
)

target_include_directories(game-engine PRIVATE ${CMAKE_SOURCE_DIR}/src/engine ${CMAKE_SOURCE_DIR}/src/sandbox)

add_subdirectory(libs/)

target_link_libraries(game-engine SDL2main SDL2 SDL2_image spdlog::spdlog glad IMGUI glm)

target_precompile_headers(game-engine PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/headers.h)
