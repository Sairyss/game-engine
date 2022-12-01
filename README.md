# Game engines resources

C++ game engine development resources for educational purposes.

**This repo is work in progress and is not even half finished**, but you still can find some useful links and code examples here.

## Creating a window

[SDL](https://github.com/libsdl-org/SDL) is a cross-platform library for creating a window and handling window events (keyboard presses, mouse clicks, etc.).

[OpenGL loading library](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library) called [glad](https://glad.dav1d.de/) helps with [OpenGL](https://www.opengl.org/) integration.

Alternative libraries:

- [glfw](https://www.glfw.org/)
- [sfml](https://github.com/SFML/SFML)

Code examples:

- [Window.h](src/engine/Core/Window.h) - window is abstracted. Because of this abstraction we can implement window using any library and swap it for another later if needed.
- [SDLWindow.cpp](src/engine/Platform/SDL/SDLWindow.cpp) - window implementation using SDL library.

### Handling window events

To be able to handle user input: key presses, mouse movements and clicks, etc. you will need to handle window events.

Code examples:

- [Events](src/engine/Events) - directory contains custom defined events. We define our custom events in order to not depend on any library, this way we could swap SDL for some other library relatively easily.
- [SDLWindow.cpp](src/engine/Platform/SDL/SDLWindow.cpp) - `HandleEvents()` method transforms SDL events into our custom defined events.

## User Interface

Any engine needs some kind of UI for development and debugging purposes.

[Dear ImGui](https://github.com/ocornut/imgui) is one of the best libraries for creating UIs in C++.

## Entity Component System

[Entity Component System](https://en.wikipedia.org/wiki/Entity_component_system) is a software architectural pattern for the representation of game world objects.

[EnTT](https://github.com/skypjack/entt) is one of the most popular ECS libraries in C++.

Resources:

- [The Entity-Component-System - An awesome game-design pattern in C++](https://www.gamedeveloper.com/design/the-entity-component-system---an-awesome-game-design-pattern-in-c-part-1-)
- [awesome-ecs](https://github.com/jslee02/awesome-entity-component-system)

## Math calculations

Libraries:

[glm](https://github.com/g-truc/glm) math library for graphics software based on the OpenGL Shading Language (GLSL) specifications.

## Tiles

For creating tiles, maps, etc.

Tools:

- [Tilesetter](https://www.tilesetter.org/)
- [Tiled](https://www.mapeditor.org/)

## 2D Physics

Libraries:

- [box2d](https://box2d.org/)

Resources:

- [2D Game Physics Programming](https://pikuma.com/courses/game-physics-engine-programming)

## Logging

It's important to have extensive logs in your application to understand what is happening and when.

[spdlog](https://github.com/gabime/spdlog) is one of the libraries that can be used for logging.

Code examples:

- [Log.h](src/engine/Core/Log.h) - logger is abstracted so we can use any library we want.

## Performance tips

### Batch rendering

Rendering large amounts of objects can affect performance. Batch rendering is an optimization technique to make your game faster.

Resources:

- [OpenGL Batch Rendering](https://www.gamedev.net/tutorials/programming/graphics/opengl-batch-rendering-r3900/)
- [Batch Rendering](https://youtu.be/biGF6oLxgtQ)

### Data locality

Data locality, or [locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference), is the tendency of a processor to access the same set of memory locations repetitively over a short period of time.

We can utilize this knowledge together with optimizations like [Data-oriented design](https://en.wikipedia.org/wiki/Data-oriented_design) to improve performance when processing large arrays of data.

Resources:

- [Data Locality](https://gameprogrammingpatterns.com/data-locality.html)

### Profiling

TODO

## Additional resources

### Articles

- [How to Make Your Own C++ Game Engine](https://www.gamedeveloper.com/blogs/how-to-make-your-own-c-game-engine)
- [Networking](https://gafferongames.com/tags/networking/)

## Sprites

Resources:

- [opengameart.org](https://opengameart.org/) - free game art

### Repositories

- [Game Networking Resources](https://github.com/ThusSpokeNomad/GameNetworkingResources)

### Tools

- [MagicaVoxel](https://ephtracy.github.io/) - GPU-based voxel art editor
- [GoNorth](https://github.com/steffendx/GoNorth) - a web application used for planning the story and world of RPGs or other open world games.

### Videos

- [How To Make A Game In C++ & SDL2 From Scratch!](https://youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
- [Game Engine Tutorial](https://youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) - a lot of the code in this repo is inspired by this tutorial series.
- [Networking in C++ Part #1: MMO Client/Server, ASIO & Framework Basics](https://youtu.be/2hNdkYInj4g)
