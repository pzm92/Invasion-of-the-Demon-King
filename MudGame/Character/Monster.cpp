#include "Monster.h"

Monster::Monster(MonsterList n)
{
	if (n == MonsterList::NORMAL)
	{
		name = "�ʷ��Ǻ�(���)";
		level = rand() % 5;
		hp = 10 + level;
		mp = 0;
		atk = 2;
		atkValue = 1 + level;
	}
	else if (n == MonsterList::HARD)
	{
		name = "��Ű(��ť����)";
		level = rand() % 5;
		hp = 20 + level * 2;
		mp = 0;
		atk = 4;
		atkValue = 1 + level;
	}
	else if (n == MonsterList::EPIC)
	{
		name = "��ī��(����)";
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
