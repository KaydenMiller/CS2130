// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"
#include <list>
#include "Hasher.h"
#include <string>
#include "BaseConverter.h"

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
	cout << "3. Quit" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: "; 
	cin >> selection;
	cout << "---------------------------" << endl;

	AssignmentSelect(selection);
}

void AssignmentSelect(int selection)
{
	switch (selection)
	{
		case 1:
			SetAssignment();
			break;
		case 2:
			//HashingAssignment();
			BaseConverter::ToBinary(8);
			break;
		case 3:
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

	cout << "Please Input a sentence to be hashed: ";
	std::getline(cin, inputString);
	cout << "Hashed String Value: " << Hasher::HashString(inputString);
	cout << endl << "---------------------------" << endl;
}