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
	std::cout << "[�ӵ����]������ ħ��\n";
	std::cout << "1. ���� ����\n";
	std::cout << "2. ����\n";
	LINE
	int n;
	std::cin >> n;	
	if (n == 1)
	{
		// ���� ����
		user = new Ares();
		LINE
		std::cout << "������ �����մϴ�\n";
		LINE
		CurrentStage = StartStage;
		StageLoop();		
	}
	else if (n == 2)
	{
		// ���� ����
		return;
	}
}

void GamePlayCore::StageLoop()
{
	if (CurrentStage == EndStage)
		return;
	std::cout << "Stage " << num + 1 << " : " << m[num]->GetName() << "���� !\n";

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

	// ������ �޼��� ���
	std::cout << me->GetName() << "(��)�� " << Damage << "��ŭ �������� ���ߴ�.\n";
	Sleep(200);

	std::cout << enemy->GetName() << "�� ü�� : " << enemy->GetHP();	

	// me �� enemy�� �����ϴ�.
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

	// enemy �� �ǰ� 0�� ��
	
}

int GamePlayCore::BattleTurn()
{
	std::cout << "������ �����մϴ�.\n";
	bool bDie = false;
	while (bDie == 0)
	{
		std::cout << "�׼��� �����ּ��� ( 1. ����, 2. ��ų, 3. ��������, 4. �������� )\n";
		int n;
		std::cin >> n;
		LINE
			if (n == 1)
			{
				std::cout << "���� !\n";
				Attack(user, m[num]);
				if (IsDie(m[num]) == 0)
					Attack(m[num], user);
			}
			else if (n == 2)
			{
				// std::cout << "��ų (�̱���) !\n";
				int r = rand() % 2 + 1;
				if (r == 1)
				{
					output->pIO("���� �߲��Ͽ� Į�� �������ϴ�. �������� ");
					int d = rand() % 10;
					user->SetHP(user->GetHP() - d);
					string temp = std::to_string(d);
					output->pIO( temp + " ��ŭ �Խ��ϴ�.\n");
				}
				else if (r == 2)
				{
					std::cout << "��ų�ߵ�!!\n";
					Attack(user, m[num], 2.0f);
					if (IsDie(m[num]) == 0)
						Attack(m[num], user);
				}
			}
			else if (n == 3)
			{
				std::cout << "�������� ( ���� Stage " << num + 1 << "������ )\n";
				user->CharacterInfo();
				m[num]->CharacterInfo();
			}
			else if (n == 4)
			{
				std::cout << "������ ����˴ϴ�.\n";
				return 0;
			}
		bDie = IsDie(user);
		bDie |= IsDie(m[num]);
	}
	std::cout << "��������.\n";
	Sleep(5000);
	return 1;
}

void GamePlayCore::GameRetry()
{
	system("cls");
	LINE;
	std::cout << "������ �����ϰڽ��ϱ�? ( 1. �� / 2. �ƴϿ� ) : ";
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
		std::cout << c->GetName() << "(��)�� ����Ͽ����ϴ�.\n";
		return true;
	}
	return false;
}

void GamePlayCore::StoryScript()
{
	output->pIO("�����\n");
	output->pIO("���迡�� �� ������� ���� ��ī���� �ΰ��踦 ��ģ��.\n�ΰ���� �ϳ��� ����� �����Ǿ� �־��� �� �̸��� \'����Ʈ\' �̴�.\n������ �ΰ���� ħ���ؼ� ����Ʈ�� �ֿ� �������� �̸����� �����Ѵ�.\n\n");
	output->pIO("�ó�ý�\n");
	output->pIO("������ �ΰ��迡 ħ���� �̸����� �����Ѵ�.\n���� ���տ��� ������ ���ϰ� ������ ���ֿ� ��ȥ�� ������ �����⿡\n�����ϴ� �������� ���Ű����� ���� ������ ���д�.\n\n");

	output->pIO("������ �ΰ��迡 ħ���ϸ�, \n�ΰ���� �̺��� �Ͼ�� ������ �� ��������\n�ΰ��迡 ���� �տ��� ������ ������ ���� �߻��ϰ� �ȴ�.\n\n");
	output->pIO("�� �ð� ������ �۰� �ִ� ���� �Ʒ����� ������ ���� �߰��ϰ� �ǰ�\n \'���ǰ�\'�� �տ� �ְԵǰ� ������ ��Ű�� ���� �̸������� ���Ѵ�.\n\n");
}
