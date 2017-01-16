#ifndef GAME_H
#define GAME_H

#include "Debug.h"

#include "SDL_image.h"

#include <SDL.h>
#include <vector>
#include <queue>
#include <map>


class Game
{
public:
									Game();
									~Game();

	bool							Initialize(const char* title, int xpos, int ypos, int width, int height, int flags);
	
	void							Render();
	void							Update();
	void							HandleEvents();
	void							CleanUp();

	bool							IsRunning();

private:
	bool							SetupSDL(const char* title, int xpos, int ypos, int width, int height, int flags);

private:
	SDL_Window*						_window;
	SDL_Renderer*					_renderer;

	bool							_running;

	unsigned int					_lastTime;//time of last update;
};



#endif
