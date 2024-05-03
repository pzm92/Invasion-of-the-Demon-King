#include <iostream>
#include "Library.h"
#include "GamePlayCore.h"

#pragma region Character
#include "Character/Ares.h"
#pragma endregion

int main()
{
	srand(time(NULL));
	GamePlayCore g(0, 0, 10);
	g.Initial();
	g.GameRetry();
	
}