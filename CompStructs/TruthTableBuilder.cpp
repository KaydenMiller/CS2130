#include "stdafx.h"
#include "TruthTableBuilder.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

namespace CompStructs
{
	void TruthTableBuilder::AskQuestions()
	{
		Question1();
		Question2();
		Question3();
	}

	void TruthTableBuilder::Question1()
	{
		string input;
		bool ErrorFlag;

		do
		{
			cout << "Do you want to AND or OR the two propositional variables? (AND/OR): ";
			std::getline(cin, input);
			input = ToLower(input);

			if (input == "and")
			{
				ErrorFlag = false;
			}
			else if (input == "or")
			{
				ErrorFlag = false;
			}
			else
			{
				cout << "Please Enter a valid value!" << std::endl;
				ErrorFlag = true;
			}
		} while (ErrorFlag);
	}

	void TruthTableBuilder::Question2()
	{

	}

	void TruthTableBuilder::Question3()
	{

	}

	string TruthTableBuilder::ToLower(string input)
	{
		string lowerString;
		for (char c : input)
		{
			lowerString += tolower(c);
		}
		return lowerString;
	}
}