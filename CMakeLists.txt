cmake_minimum_required(VERSION 3.0.0)
project(game-engine VERSION 0.1.0)

add_executable(game-engine src/main.cpp src/sandbox/Sandbox.cpp src/engine/Application.cpp)

target_link_libraries(game-engine SDL2main SDL2 GL SDL2_image)