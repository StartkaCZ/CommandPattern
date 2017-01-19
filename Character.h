#pragma once


class Character
{
public:
	Character();
	~Character();

	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();
};

