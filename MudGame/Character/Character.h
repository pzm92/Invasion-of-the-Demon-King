#pragma once
#include "../Library.h"

class Character
{
public:
	Character();
	Character(int level, int hp, int mp, int atk);
	~Character();

public:
	std::string GetName() { return name; }
	int GetLevel() { return level; }
	int GetHP() { return hp; }
	void SetHP(int hp) { this->hp = hp; }
	int GetMP() { return mp; }
	void SetMP(int mp) { this->mp = mp; }
	int GetATK() { return atk + atkValue; }
	float GetEXP() { return exp; }
	void SetEXP(float exp) { this->exp = exp; }

public:	
	void CharacterInfo();

public:
	void AddEXP(float add);

protected:
	std::string name;
	int level;
	float hp;
	int mp;
	int atk;
	int atkValue;
	
	float exp;
};

