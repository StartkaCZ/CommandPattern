#include "Character.h"

#include <iostream>

Character::Character()
{
}


Character::~Character()
{
}

void Character::MoveLeft()
{
	std::cout << "MOVING LEFT" << std::endl;
}
void Character::MoveRight()
{
	std::cout << "MOVING RIGHT" << std::endl;
}
void Character::MoveUp()
{
	std::cout << "MOVING UP" << std::endl;
}
void Character::MoveDown()
{
	std::cout << "MOVING DOWN" << std::endl;
}