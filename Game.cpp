#include <iostream>
#include <sstream>
#include <assert.h>

#include "Game.h"

#include "LTimer.h"


Game::Game() 
	: _running(false)
	, _commands(std::map<Command::Action, Command*>())
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
		_character = new Character();

		_commands[Command::Action::MoveDown] = new Command(Command::Action::MoveDown);
		_commands[Command::Action::MoveUp] = new Command(Command::Action::MoveUp);
		_commands[Command::Action::MoveLeft] = new Command(Command::Action::MoveLeft);
		_commands[Command::Action::MoveRight] = new Command(Command::Action::MoveRight);
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
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_a:
				std::cout << "a pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveLeft]);
				break;
			case SDLK_d:
				std::cout << "d pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveRight]);
				break;
			case SDLK_w:
				std::cout << "w pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveUp]);
				break;
			case SDLK_s:
				std::cout << "s pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveDown]);


			case SDLK_LEFT:
				std::cout << "left pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveLeft]);
				break;
			case SDLK_RIGHT:
				std::cout << "right pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveRight]);
				break;
			case SDLK_UP:
				std::cout << "up pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveUp]);
				break;
			case SDLK_DOWN:
				std::cout << "down pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveDown]);
				break;

			case SDLK_SPACE:
				std::cout << "space pressed" << std::endl;
				_macroCommand.Add(_commands[Command::Action::MoveUp]);
				break;


			case SDLK_BACKSPACE:
				std::cout << "undo pressed" << std::endl;
				_macroCommand.Undo(_character);
				break;

			case SDLK_RETURN:
				std::cout << "enter pressed" << std::endl;
				_macroCommand.Execute(_character);
				break;

			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			}
			break;

		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{

			}
			break;

		default:
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
	delete _commands[Command::Action::MoveDown];
	delete _commands[Command::Action::MoveUp];
	delete _commands[Command::Action::MoveLeft];
	delete _commands[Command::Action::MoveRight];
	_commands.clear();

	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}
