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
	std::cout << "�̸� : " << name << "\n";
	std::cout << "���� : " << level << "\n";
	std::cout << "ü�� : " << hp << "\n";
	std::cout << "���� : " << mp << "\n";
	std::cout << "���ݷ� : " << atk << " ~ " << atk + atkValue << "\n";
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
	std::cout << level << "������ ���!\n";
	std::cout << level * 5 << "��ŭ ȸ���մϴ�.\n";

}
