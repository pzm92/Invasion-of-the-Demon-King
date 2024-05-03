#include "Monster.h"

Monster::Monster(MonsterList n)
{
	if (n == MonsterList::NORMAL)
	{
		name = "초록피부(고블린)";
		level = rand() % 5;
		hp = 10 + level;
		mp = 0;
		atk = 2;
		atkValue = 1 + level;
	}
	else if (n == MonsterList::HARD)
	{
		name = "리키(서큐버스)";
		level = rand() % 5;
		hp = 20 + level * 2;
		mp = 0;
		atk = 4;
		atkValue = 1 + level;
	}
	else if (n == MonsterList::EPIC)
	{
		name = "루카스(마왕)";
		level = 100;
		hp = 100;
		mp = 0;
		atk = 10;
		atkValue = 1 ;
	}
}

Monster::~Monster()
{
}
