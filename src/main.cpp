// Source : https://gist.github.com/jordandee/94b187bcc51df9528a2f
// To compile with gcc:	(tested on Ubuntu 14.04 64bit):
//	 g++ sdl2_opengl.cpp -lSDL2 -lGL
// To compile with msvc: (tested on Windows 7 64bit)
//	 cl sdl2_opengl.cpp /I C:\sdl2path\include /link C:\path\SDL2.lib C:\path\SDL2main.lib /SUBSYSTEM:CONSOLE /NODEFAULTLIB:libcmtd.lib opengl32.lib

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef int32_t b32;

#define WinWidth 800
#define WinHeight 600

int main ()
{

	u32 WindowFlags = SDL_WINDOW_OPENGL;
	SDL_Window *Window = SDL_CreateWindow("OpenGL Test", 0, 0, WinWidth, WinHeight, WindowFlags);
	assert(Window);
	SDL_GLContext Context = SDL_GL_CreateContext(Window);
	
	
	b32 Running = 1;
	b32 FullScreen = 0;
	while (Running)
	{
		SDL_Event Event;
		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_KEYDOWN)
			{
				switch (Event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Running = 0;
						break;
					case 'f':
						FullScreen = !FullScreen;
						if (FullScreen)
						{
							SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
						}
						else
						{
							SDL_SetWindowFullscreen(Window, WindowFlags);
						}
						break;
					default:
						break;
				}
			}
			else if (Event.type == SDL_QUIT)
			{
				Running = 0;
			}
		}

		glViewport(0, 0, WinWidth, WinHeight);
		glClearColor(1.f, 0.f, 1.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(Window);
	}
	SDL_GL_DeleteContext(Context);
	return 0;
}
