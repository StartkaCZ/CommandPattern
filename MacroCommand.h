#pragma once

#include "Command.h"
#include "Character.h"

#include <vector>

class MacroCommand : public Command
{
public:
							MacroCommand();
	virtual					~MacroCommand();

	virtual void			Add(Command* command);
	virtual void			Remove(Command* command);

	virtual void			Execute(Character*& character) override;
	virtual void			Undo(Character*& character) override;

	bool					isEmpty() const;

private:
	std::vector<Command*>*	_commands;
	int						_currentCommand;
};

