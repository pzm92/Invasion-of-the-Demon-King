#pragma once
#include "Character.h"

enum class MonsterList
{
	NORMAL = 1,
	HARD,
	EPIC
};

class Monster : public Character
{
public:
	Monster(MonsterList n);
	~Monster();

private:

};

