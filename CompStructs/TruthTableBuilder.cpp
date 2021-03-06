#include "stdafx.h"
#include "TruthTableBuilder.h"
#include <string>
#include <iostream>
#include <iomanip>

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
		cin.ignore();

		do
		{
			cout << "Do you want to AND or OR the two propositional variables? (AND/OR): ";
			std::getline(cin, input);
			input = ToLower(input);

			if (input == "and")
			{
				ErrorFlag = false;
				AND = true;
			}
			else if (input == "or")
			{
				ErrorFlag = false;
				OR = true;
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
		string input;
		bool ErrorFlag;

		do
		{
			cout << "Do you want to NOT p? (y/n): ";
			std::getline(cin, input);
			input = ToLower(input);

			if (input == "y")
			{
				NOTp = true;
				ErrorFlag = false;
			}
			else if (input == "n")
			{
				NOTp = false;
				ErrorFlag = false;
			}
			else
			{
				cout << "Please Enter a valid value!" << std::endl;
				ErrorFlag = true;
			}
		} while (ErrorFlag);
	}

	void TruthTableBuilder::Question3()
	{
		string input;
		bool ErrorFlag;

		do
		{
			cout << "Do you want to NOT q? (y/n): ";
			std::getline(cin, input);
			input = ToLower(input);

			if (input == "y")
			{
				NOTq = true;
				ErrorFlag = false;
			}
			else if (input == "n")
			{
				NOTq = false;
				ErrorFlag = false;
			}
			else
			{
				cout << "Please Enter a valid value!" << std::endl;
				ErrorFlag = true;
			}
		} while (ErrorFlag);
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

	void TruthTableBuilder::OutputTable()
	{
		const unsigned char F = 0x00; // 0000 0000
		const unsigned char T = 0x01; // 0000 0001

		const unsigned char p[4] = { T, T, F, F };
		const unsigned char q[4] = { T, F, T, F };
		unsigned char outputArray[4];

		// calculate the output of the prop. statement
		if (AND)
		{
			// AND
			if (NOTp && NOTq)
			{
				// ~p A ~q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = !p[i] && !q[i];
				}
			}
			else if (NOTp)
			{
				// ~p A q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = !p[i] && q[i];
				}
			}
			else if (NOTq)
			{
				// p A ~q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = p[i] && !q[i];
				}
			}
			else
			{
				// p A q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = p[i] && q[i];
				}
			}
		}
		else
		{
			// OR
			if (NOTp && NOTq)
			{
				// ~p V ~q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = !p[i] || !q[i];
				}
			}
			else if (NOTp)
			{
				// ~p V q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = !p[i] || q[i];
				}
			}
			else if (NOTq)
			{
				// p V ~q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = p[i] || !q[i];
				}
			}
			else
			{
				// p V q
				for (int i = 0; i < 4; i++)
				{
					outputArray[i] = p[i] || q[i];
				}
			}
		}

		// display the output
		cout << std::setw(1) << std::right << "| p |"
			 << std::setw(1) << std::right << " q | " 
			 << std::setw(1) << BuildPropStatement() << " |" << std::endl;
		cout << std::setw(1) << std::right << "| T | T | " << GetLogicalEquivalent(outputArray[0]) << " |" << std::endl;
		cout << std::setw(1) << std::right << "| T | F | " << GetLogicalEquivalent(outputArray[1]) << " |" << std::endl;
		cout << std::setw(1) << std::right << "| F | T | " << GetLogicalEquivalent(outputArray[2]) << " |" << std::endl;
		cout << std::setw(1) << std::right << "| F | F | " << GetLogicalEquivalent(outputArray[3]) << " |" << std::endl;
		
	}

	void TruthTableBuilder::OutputLargeTable()
	{
		// this is just to make typeing the array easier
		const bool T = true;
		const bool F = false;
		
		//					 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
		const bool a[32] = { T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T,
							 F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F };

		const bool b[32] = { T, T, T, T, T, T, T, T, F, F, F, F, F, F, F, F,
							 T, T, T, T, T, T, T, T, F, F, F, F, F, F, F, F };

		const bool c[32] = { T, T, T, T, F, F, F, F, T, T, T, T, F, F, F, F,
							 T, T, T, T, F, F, F, F, T, T, T, T, F, F, F, F };

		const bool d[32] = { T, T, F, F, T, T, F, F, T, T, F, F, T, T, F, F,
							 T, T, F, F, T, T, F, F, T, T, F, F, T, T, F, F };

		const bool e[32] = { T, F, T, F, T, F, T, F, T, F, T, F, T, F, T, F,
							 T, F, T, F, T, F, T, F, T, F, T, F, T, F, T, F };

		bool output[32];
		
		for (int i = 0; i < 32; i++)
		{
			output[i] = (((c[i] || !d[i]) && b[i]) && !(d[i] || a[i] && e[i]));
		}

		cout << "| a | b | c | d | e | (( c V ~d) A b) A ~( d V a A e) |" << std::endl;
		cout << "-------------------------------------------------------" << std::endl;
		for (int i = 0; i < 32; i++)
		{
			if (i == 16)
				cout << "-------------------------------------------------------" << std::endl;

			cout << "| " << GetLogicalEquivalent(a[i]) << " | " << GetLogicalEquivalent(b[i]) << " | "
				<< GetLogicalEquivalent(c[i]) << " | " << GetLogicalEquivalent(d[i]) << " | "
				<< GetLogicalEquivalent(e[i]) << " | " << 
				std::setw(17) << GetLogicalEquivalent(output[i]) << std::setw(17) << " | " << std::endl;
		}
		cout << "-------------------------------------------------------" << std::endl;

	}

	string TruthTableBuilder::GetLogicalEquivalent(unsigned char input)
	{
		switch (input)
		{
			case 0x00:
				return "F";
			case 0x01:
				return "T";
		}
	}

	string TruthTableBuilder::GetLogicalEquivalent(bool input)
	{
		switch (input)
		{
			case false:
				return "F";
			case true:
				return "T";
		}
	}

	string TruthTableBuilder::BuildPropStatement()
	{
		string p;
		string q;
		string op;

		switch (NOTp)
		{
			case true:
				p = "~p";
				break;
			case false:
				p = "p";
				break;
		}

		switch (NOTq)
		{
			case true:
				q = "~q";
				break;
			case false:
				q = "q";
				break;
		}

		if (AND)
		{
			op = " A ";
		}
		else
		{
			op = " V ";
		}

		return (p + op + q);
	}

	
}