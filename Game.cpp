#include <iostream>
#include <sstream>
#include <assert.h>

#include "Game.h"

#include "LTimer.h"


Game::Game() 
	: _running(false)
{
}

Game::~Game()
{
}


bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	_running = SetupSDL(title, xpos, ypos, width, height, flags);
	
	if (_running)
	{//SETUP WHATEVER NEEDS TO BE SETUP
		
	}

	return _running;
}
bool Game::SetupSDL(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		DEBUG_MSG("SDL Init success");
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (_window != 0)
		{
			DEBUG_MSG("Window creation success");
			_renderer = SDL_CreateRenderer(_window, -1, 0);
			if (_renderer != 0)
			{
				DEBUG_MSG("Renderer creation success");
				SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
			}
			else
			{
				DEBUG_MSG("Renderer init fail");
				return false;
			}
		}
		else
		{
			DEBUG_MSG("Window init fail");
			return false;
		}
	}
	else
	{
		DEBUG_MSG("SDL init fail");
		return false;
	}

	return true;
}

void Game::Update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - _lastTime;//time since last update


	//UPDATE HERE
	

	//save the curent time for next frame
	_lastTime = currentTime;
}

void Game::Render()
{
	SDL_RenderClear(_renderer);

	//RENDER HERE
	

	SDL_SetRenderDrawColor(_renderer, 55, 55, 55, 255);
	SDL_RenderPresent(_renderer);
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				_running = false;
				break;

			default:
				break;
			}
			break;
		}
	}
}

bool Game::IsRunning()
{
	return _running;
}


void Game::CleanUp()
{
	DEBUG_MSG("Cleaning Up");

	//DESTROY HERE


	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}