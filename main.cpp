// Lighting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameController.h"

int main(void)
{
	GameController::GetInstance().Initialize();

	GameController::GetInstance().RunGame();

	return 0;
}
