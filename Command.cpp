#include "Command.h"


Command::Command()
	: _action(Action::Nothing)
{

}
Command::Command(Action action)
	: _action(action)
{
}


Command::~Command()
{
}

void Command::Execute(Character*& character)
{
	switch (_action)
	{
	case Command::Action::MoveUp:
		character->MoveUp();
		break;
	case Command::Action::MoveDown:
		character->MoveDown();
		break;
	case Command::Action::MoveRight:
		character->MoveRight();
		break;
	case Command::Action::MoveLeft:
		character->MoveLeft();
		break;
	default:
		break;
	}
}
void Command::Undo(Character*& character)
{
	switch (_action)
	{
	case Command::Action::MoveUp:
		character->MoveDown();
		break;
	case Command::Action::MoveDown:
		character->MoveUp();
		break;
	case Command::Action::MoveRight:
		character->MoveLeft();
		break;
	case Command::Action::MoveLeft:
		character->MoveRight();
		break;
	default:
		break;
	}
}
