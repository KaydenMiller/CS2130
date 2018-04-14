#include "stdafx.h"
#include "MontyHall.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

namespace CompStructs
{
	bool MontyHall::RunTest(bool switchDoors)
	{
		int choice = rand() % 3 + 1;
		int correctChoice = 1;

		if (switchDoors)
		{
			choice = SwitchChoices(choice);
		}

		if (correctChoice == choice)
			return true;
		else
			return false;

	}

	float MontyHall::CalculateProbability(bool switchDoors)
	{
		float wins = 0;

		for (int i = 0; i < TIMES_TO_RUN; i++)
			RunTest(switchDoors) ? wins++ : wins += 0;

		return wins / TIMES_TO_RUN;
	}

	int MontyHall::SwitchChoices(int choice)
	{
		if (choice == 2 || choice == 3)
			return 1;
		else
			return rand() % 3 + 2;
	}

	void MontyHall::OutputTestResults()
	{
		cout << "Probability with Switching: " << CalculateProbability(true) << endl;
		cout << "Probability without switching: " << CalculateProbability(false) << endl;
	}
}