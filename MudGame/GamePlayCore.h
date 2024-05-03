#pragma once
#include "Library.h"
#include "Character/Character.h"
#include "Character/Ares.h"
#include "Character/Monster.h"
#include "Utillity/StrOutput.h"

class GamePlayCore
{
public:
	GamePlayCore(int s, int c, int e);
	~GamePlayCore();
	


public:
	void Initial();
	void StageLoop();
public:
	void Attack(Character* me, Character* enemy, float multiple = 1.0f);
	void StageInfo() {};

public:
	int BattleTurn();

public:
	void GameRetry();
	bool IsDie(Character* c);

public:
	void StoryScript();

private:
	Ares* user;
	Monster* m[10];
	StrOutput* output;
	int StartStage;
	int CStage;
	int EndStage;

	int CurrentStage = 0;

	int num = 0;

private:
	bool bStoryView = true;
};