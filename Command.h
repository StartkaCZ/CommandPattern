#pragma once

#include "Character.h"

class Command
{
public:
	enum class Action
	{
		Nothing,
		MoveUp,
		MoveDown,
		MoveRight,
		MoveLeft
	};

public:
					Command();
					Command(Action action);
	virtual			~Command();

	virtual void	Execute(Character*& character);
	virtual void	Undo(Character*& character);

private:
	Action			_action;
};

