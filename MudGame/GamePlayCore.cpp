#include "GamePlayCore.h"

GamePlayCore::GamePlayCore(int s, int c, int e)
{
	user = nullptr;
	for (size_t i = 0; i < 10; i++)
		m[i] = nullptr;
	for (size_t i = 0; i < e - s; i++)
		m[i] = new Monster((MonsterList)(i % 3 + 1));
	StartStage = s;
	CStage = c;
	EndStage = e;	

	output = new StrOutput();
}

GamePlayCore::~GamePlayCore()
{
}

void GamePlayCore::Initial()
{
	//if (bStoryView == true)
	//{
	//	StoryScript();
	//	bStoryView = false;
	//}
	LINE
	std::cout << "[머드게임]마왕의 침략\n";
	std::cout << "1. 게임 시작\n";
	std::cout << "2. 종료\n";
	LINE
	int n;
	std::cin >> n;	
	if (n == 1)
	{
		// 게임 시작
		user = new Ares();
		LINE
		std::cout << "게임을 시작합니다\n";
		LINE
		CurrentStage = StartStage;
		StageLoop();		
	}
	else if (n == 2)
	{
		// 게임 종료
		return;
	}
}

void GamePlayCore::StageLoop()
{
	if (CurrentStage == EndStage)
		return;
	std::cout << "Stage " << num + 1 << " : " << m[num]->GetName() << "등장 !\n";

	if (BattleTurn() == 0)
		return;

	if (IsDie(user))
		return;
	num++;
	CurrentStage++;
	StageLoop();
}

void GamePlayCore::Attack(Character* me, Character* enemy, float multiple)
{
	float preEnemyHP = enemy->GetHP();
	float Damage = me->GetATK() * multiple;

	// 데미지 메세지 출력
	std::cout << me->GetName() << "(이)가 " << Damage << "만큼 데미지를 가했다.\n";
	Sleep(200);

	std::cout << enemy->GetName() << "의 체력 : " << enemy->GetHP();	

	// me 가 enemy를 공격하다.
	enemy->SetHP(enemy->GetHP() - Damage);

	std::cout << " --> ";
	if (enemy->GetHP() < 0)
	{
		std::cout << 0 << "\n";
		me->AddEXP(50.0f);
	}
	else 
		std::cout << enemy->GetHP() << "\n";
	Sleep(200);

	// enemy 의 피가 0일 때
	
}

int GamePlayCore::BattleTurn()
{
	std::cout << "전투를 시작합니다.\n";
	bool bDie = false;
	while (bDie == 0)
	{
		std::cout << "액션을 취해주세요 ( 1. 공격, 2. 스킬, 3. 스텟정보, 4. 게임포기 )\n";
		int n;
		std::cin >> n;
		LINE
			if (n == 1)
			{
				std::cout << "공격 !\n";
				Attack(user, m[num]);
				if (IsDie(m[num]) == 0)
					Attack(m[num], user);
			}
			else if (n == 2)
			{
				// std::cout << "스킬 (미구현) !\n";
				int r = rand() % 2 + 1;
				if (r == 1)
				{
					output->pIO("손이 삐끗하여 칼에 베였습니다. 데미지를 ");
					int d = rand() % 10;
					user->SetHP(user->GetHP() - d);
					string temp = std::to_string(d);
					output->pIO( temp + " 만큼 입습니다.\n");
				}
				else if (r == 2)
				{
					std::cout << "스킬발동!!\n";
					Attack(user, m[num], 2.0f);
					if (IsDie(m[num]) == 0)
						Attack(m[num], user);
				}
			}
			else if (n == 3)
			{
				std::cout << "스텟정보 ( 현재 Stage " << num + 1 << "진행중 )\n";
				user->CharacterInfo();
				m[num]->CharacterInfo();
			}
			else if (n == 4)
			{
				std::cout << "게임이 종료됩니다.\n";
				return 0;
			}
		bDie = IsDie(user);
		bDie |= IsDie(m[num]);
	}
	std::cout << "전투종료.\n";
	Sleep(5000);
	return 1;
}

void GamePlayCore::GameRetry()
{
	system("cls");
	LINE;
	std::cout << "게임을 종료하겠습니까? ( 1. 예 / 2. 아니오 ) : ";
	int n;
	std::cin >> n;
	if (n == 1)
	{
		return;
	}
	else if (n == 2)
	{
		Initial();
	}
}

bool GamePlayCore::IsDie(Character* c)
{
	if (c->GetHP() < 0)
	{
		std::cout << c->GetName() << "(이)가 사망하였습니다.\n";
		return true;
	}
	return false;
}

void GamePlayCore::StoryScript()
{
	output->pIO("세계관\n");
	output->pIO("마계에서 온 마족들과 마왕 루카스가 인간계를 덮친다.\n인간계는 하나의 나라로 구성되어 있었고 그 이름은 \'루인트\' 이다.\n마왕은 인간계로 침투해서 루인트의 주요 도심지인 미르성을 점령한다.\n\n");
	output->pIO("시놉시스\n");
	output->pIO("마왕은 인간계에 침투해 미르성을 점령한다.\n왕은 마왕에게 죽임을 당하고 마왕은 공주와 결혼할 생각을 가졌기에\n저항하는 마리네의 정신개조를 위해 감옥에 가둔다.\n\n");

	output->pIO("마왕이 인간계에 침투하며, \n인간계는 이변이 일어나고 세상의 한 구석에서\n인간계에 생긴 균열에 대항할 미지의 힘이 발산하게 된다.\n\n");
	output->pIO("그 시각 무예를 닦고 있던 무사 아레스가 미지의 힘을 발견하게 되고\n \'빛의검\'을 손에 넣게되고 세상을 지키기 위해 미르성으로 향한다.\n\n");
}
