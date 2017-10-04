// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"
#include <list>
#include "Hasher.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using CompStructs::Set;
using CompStructs::Hasher;
using std::exit;

void AssignmentSelect(int);
void SetAssignment();
void HashingAssignment();
void GenerateSequenceAssignment();
void Menu();

int main()
{
	do
	{
		Menu();
	} while (true);

    return 0;
}

void Menu()
{	
	int selection;

	cout << "---------------------------" << endl;
	cout << "Please Enter A Selection:" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Sets (Const Values)" << endl;
	cout << "2. Hashing (string)" << endl;
	cout << "3. Display Sequence" << endl;
	cout << "4. Quit" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: "; 
	cin >> selection;
	cout << "---------------------------" << endl;
	if (cin.good())
	{
		AssignmentSelect(selection);
		cout << endl;
	}
	else
	{
		cout << "Please enter a valid integer!" << endl;
	}
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
			exit(0);
			break;
		default:
			cout << "Invalid Responce Try Again!" << endl;
			cout << "---------------------------" << endl;
			break;
	}
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
}