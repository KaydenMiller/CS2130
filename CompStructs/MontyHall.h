#pragma once
namespace CompStructs
{
	// The probability of winning without switching 1/3 and with is 2/3
	static class MontyHall
	{
	private:
		static const int TIMES_TO_RUN = 10000;
		static int SwitchChoices(int choice);
		static bool RunTest(bool switchDoors);
	public:
		static float CalculateProbability(bool switchDoors);
		static void OutputTestResults();
	};
}
