#include "Character.h"

Character::Character()
{
	level = 0;
	hp = 0;
	mp = 0;
	atk = 0;
	exp = 0.0f;
}

Character::Character(int level, int hp, int mp, int atk)
{
	this->level = level;
	this->hp = hp;
	this->mp = mp;
	this->atk = atk;
}
Character::~Character()
{

}


void Character::CharacterInfo()
{
	LINE
	std::cout << "이름 : " << name << "\n";
	std::cout << "레벨 : " << level << "\n";
	std::cout << "체력 : " << hp << "\n";
	std::cout << "마력 : " << mp << "\n";
	std::cout << "공격력 : " << atk << " ~ " << atk + atkValue << "\n";
	LINE
}

void Character::AddEXP(float add)
{
	exp += add;
	if (exp >= 100.0f)
	{
		exp -= 100.0f;
		level++;
	}
	SetHP(GetHP() + level * 5);
	std::cout << level << "레벨로 상승!\n";
	std::cout << level * 5 << "만큼 회복합니다.\n";

}
