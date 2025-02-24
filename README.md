**Game Engine Overview**
=======================

This is a game engine made for entertainment and training purpose. The end goal is to create a roguelike procedural game like an old game I made in Unity, [PPBB or Panpanboumboum](https://pyroblastouille.itch.io/panpanboumboum).

This project aims to be modular, similar to Unity. By default, all objects have a Transform component, which consists of a position, rotation, and scale. We can further enhance the engine by incorporating additional modules, such as a Sprite Renderer, Box Collider, and other components, to expand its functionality.

**Technical Details**
--------------------

* **SDL2 version**: 2.30.0
* **OpenGL version**: 4.6
* **Programming languages**: C++
* **Build system**: Makefile


**Requirements**
-----------------

- libsdl2-dev
- libsdl2-image-dev
- make
- g++

**Getting Started**
-------------------

To get started with the engine, follow these steps:

1. Clone the repository or download the latest release.
2. Install the required dependencies, including SDL2 and OpenGL. ([See Requirements](#requirements))
3. The application's entry point is `src/main.cpp` by default.
4. To build the engine and/or your project, run the command: `make`.
5. By default, the compiled application executable can be found at: `build/myprogram` (Or use the command `make run`)

**License**
---------

The engine is licensed under the MIT License. See the [license file](LICENSE) for more information.