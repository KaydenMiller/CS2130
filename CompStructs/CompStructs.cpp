// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"
#include <list>
#include "Hasher.h"
#include <string>
#include "BaseConverter.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TruthTableBuilder.h"
#include "StatsMath.h"
#include "MontyHall.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using CompStructs::Set;
using CompStructs::Hasher;
using CompStructs::BaseConverter;
using CompStructs::TruthTableBuilder;
using CompStructs::StatsMath;
using CompStructs::MontyHall;
using std::exit;

void AssignmentSelect(int);
void SetAssignment();
void HashingAssignment();
void GenerateSequenceAssignment();
void BaseConversionsAssignment();
void Menu();
void CreateTruthTable();
void CreateLargeTruthTable();
void PermutationsAndCombinations();
void MontyHallProblem();


int main()
{
	do
	{
		Menu();
	} while (true);

    return 0;
}

bool IsNumeric(const std::string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
}

void Menu()
{	
	string input;

	cout << "---------------------------" << endl;
	cout << "Please Enter A Selection:" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Sets (Const Values) Assignment 1" << endl;
	cout << "2. Hashing (string) Assignment 2" << endl;
	cout << "3. Display Sequence Assignment 3" << endl;
	cout << "4. Convert Bases Assignment 4" << endl;
	cout << "5. Create Truth Table Assignment 5" << endl;
	cout << "6. Create Large Truth Table Assignment 6" << endl;
	cout << "7. Permutations and Combinations Assignment 7" << endl;
	cout << "8. Monty Hall Problem Assignment 8" << endl;
	cout << "9. Quit" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: "; cin >> input;
	cout << "---------------------------" << endl;
	if (IsNumeric(input))
	{
		AssignmentSelect(std::stoi(input));
		cout << endl;
	}
	else
	{
		cout << "Please enter a valid integer!" << endl;
	}
	system("PAUSE");
	system("CLS");
}

void AssignmentSelect(int selection)
{
	switch (selection)
	{
		case 1:
			SetAssignment();
			break;
		case 2:
			HashingAssignment();
			break;
		case 3:
			GenerateSequenceAssignment();
			break;
		case 4:
			BaseConversionsAssignment();
			break;
		case 5:
			CreateTruthTable();
			break;
		case 6:
			CreateLargeTruthTable();
			break;
		case 7:
			PermutationsAndCombinations();
			break;
		case 8:
			MontyHallProblem();
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Invalid Responce Try Again!" << endl;
			cout << "---------------------------" << endl;
			break;
	}
}

void MontyHallProblem()
{
	MontyHall::OutputTestResults();
}


void PermutationsAndCombinations()
{
	string inputn, inputr;
	long n, r;
	cin.ignore();

	cout << "What is the number of n: ";
	cin >> inputn;
	cout << "What is the number of r: ";
	cin >> inputr;

	if (IsNumeric(inputn) && IsNumeric(inputr))
	{
		n = std::stol(inputn);
		r = std::stol(inputr);

		cout << "---------------------------" << endl;
		
		cout << "Combination With Repeats: " << StatsMath::Combination(n, r, true) << endl;
		cout << "Combination without Repeats: " << StatsMath::Combination(n, r, false) << endl;
		cout << "Permutation With Repeats: " << StatsMath::Permutation(n, r, true) << endl;
		cout << "Permutation without Repeats: " << StatsMath::Permutation(n, r, false) << endl;
	}
	else
	{
		cout << "Please input a valid long or int value!" << endl;
	}
}

void CreateLargeTruthTable()
{
	TruthTableBuilder truthTableBuilder;
	truthTableBuilder.OutputLargeTable();
}

void CreateTruthTable()
{
	TruthTableBuilder truthTableBuilder;
	truthTableBuilder.AskQuestions();
	truthTableBuilder.OutputTable();
}

void SetAssignment()
{
	list<int> setA = { 1, 3, 5, 6, 8 };
	list<int> setB = { 2, 3, 4, 7, 9 };
	
	Set A = Set(setA);
	Set B = Set(setB);

	cout << "Set A: " << A << endl;
	cout << "Set B: " << B << endl;
	cout << "---------------------------" << endl;
	cout << "Subtraction: " << (A - B);
	cout << endl << "---------------------------" << endl;
	cout << "Union: " << Set::Union(A, B);
	cout << endl << "---------------------------" << endl;
	cout << "Intersection: " << Set::Intersection(A, B);
	cout << endl << "---------------------------" << endl;
}

void HashingAssignment()
{
	string inputString;
	cin.ignore();

	cout << "Please Input a sentence to be hashed: ";
	std::getline(cin, inputString);
	cout << "Hashed String Value: " << Hasher::HashString(inputString);
	cout << endl << "---------------------------" << endl;
}

// generate and display the following sequence A = (11110000  111000  1100  10)
void GenerateSequenceAssignment()
{
	for (int i = 4; i >= 1; i--)
	{
		for (int j = i; j > 0; j--)
			cout << 1;

		for (int j = i; j > 0; j--)
			cout << 0;
	}
	cout << endl << "---------------------------" << endl;
}

void BaseConversionsAssignment()
{
	cin.ignore();
	cout << "Please Enter an INT to convert: ";
	string input;
	cin >> input;

	if (IsNumeric(input))
	{
		int value = std::stoi(input);
		if (value >= 0)
		{
			cout << "BIN: " << BaseConverter::ToBinary(value) << endl;
			cout << "OCT: " << BaseConverter::ToOct(value) << endl;
			cout << "HEX: " << BaseConverter::ToHex(value) << endl;
		}
		else
		{
			cout << "Please enter non-negative Integer values only!" << endl;
		}
	}
	else
	{
		cout << "Please enter non-negative Integer values only!" << endl;
	}
	cout << endl << "---------------------------" << endl;
}

