#include "MacroCommand.h"



MacroCommand::MacroCommand()
	: _commands(new std::vector<Command*>())
	, _currentCommand(0)
{
}


MacroCommand::~MacroCommand()
{
}

void MacroCommand::Add(Command* command)
{
	_commands->push_back(command);
}
void MacroCommand::Remove(Command* command)
{
	_commands->erase(std::find(_commands->begin(), _commands->end(), command));
}


void MacroCommand::Execute(Character*& character)
{
	for (; _currentCommand < _commands->size(); _currentCommand++)
	{
		_commands->at(_currentCommand)->Execute(character);
	}
}

void MacroCommand::Undo(Character*& character)
{
	if (_currentCommand > 0)
	{
		_currentCommand--;
		_commands->at(_currentCommand)->Undo(character);
	}
}


bool MacroCommand::isEmpty() const
{
	return _commands->empty();
}
