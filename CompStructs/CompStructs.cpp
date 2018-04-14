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
#include "Matrix.h"
#include <array>

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
using CompStructs::Matrix;
using std::exit;
using std::array;

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
void MatrixAssignment();
void OrderedPairs();


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
	cout << "9. Matrix Assignment 9" << endl;
	cout << "10. Ordered Pairs Assignment 10" << endl;
	cout << "11. Quit" << endl;
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
			MatrixAssignment();
			break;
		case 10:
			OrderedPairs();
			break;
		case 11:
			exit(0);
			break;
		default:
			cout << "Invalid Responce Try Again!" << endl;
			cout << "---------------------------" << endl;
			break;
	}
}

void OrderedPairs()
{
	int orderedPair[5][2];
	vector<int> domain;
	vector<int> range;

	cout << "Please enter 5 Ordered Pairs: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Ordered Pair #" << i + 1 << endl;
		cout << "Value 1: "; cin >> orderedPair[i][0];
		cout << "Value 2: "; cin >> orderedPair[i][1];
	}

	domain.push_back(orderedPair[0][0]);
	range.push_back(orderedPair[0][1]);

	for (int i = 0; i < 5; i++)
	{
		bool flag = true;

		for (vector<int>::iterator it = domain.begin(); it != domain.end(); it++)
			if (*it == orderedPair[i][0])
				flag = false;
		if (flag)
			domain.push_back(orderedPair[i][0]);

		flag = true;

		for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
			if (*it == orderedPair[i][1])
				flag = false;
		if (flag)
			range.push_back(orderedPair[i][1]);
	}

	cout << "---------------------------" << endl;

	cout << "Relation: {";
	for (int i = 0; i < 5; i++)
	{
		if (i < 4)
			cout << "(" << orderedPair[i][0] << ", " << orderedPair[i][1] << "), ";
		if (i == 4)
			cout << "(" << orderedPair[i][0] << ", " << orderedPair[i][1] << ")";
	}
	cout << "}" << endl;

	cout << "Domain: {";
	for (vector<int>::iterator it = domain.begin(); it != domain.end(); it++)
	{
		if (it != domain.end() - 1)
			cout << *it << ", ";
		else
			cout << *it;
	}
	cout << "}" << endl;

	cout << "Range: {";
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
	{
		if (it != range.end() - 1)
			cout << *it << ", ";
		else
			cout << *it;
	}
	cout << "}" << endl;
}

void MatrixAssignment()
{
	vector<vector<int>> a, b, c, d;

	a.resize(2);
	a[0].resize(2);
	a[1].resize(2);
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 2;
	a[1][1] = 3;
	Matrix A = Matrix(2, 2);
	A.build(a);

	b.resize(2);
	b[0].resize(3);
	b[1].resize(3);
	b[0][0] = 4;
	b[0][1] = 5;
	b[0][2] = 1;
	b[1][0] = 5;
	b[1][1] = 6;
	b[1][2] = 12;
	Matrix B = Matrix(2, 3);
	B.build(b);

	c.resize(3);
	c[0].resize(2);
	c[1].resize(2);
	c[2].resize(2);
	c[0][0] = 6;
	c[0][1] = -1;
	c[1][0] = 7;
	c[1][1] = -9;
	c[2][0] = 2;
	c[2][1] = 0;
	Matrix C = Matrix(3, 2);
	C.build(c);

	d.resize(3);
	d[0].resize(3);
	d[1].resize(3);
	d[2].resize(3);
	d[0][0] = 9;
	d[0][1] = 5;
	d[0][2] = 3;
	d[1][0] = -1;
	d[1][1] = 0;
	d[1][2] = 5;
	d[2][0] = 12;
	d[2][1] = 0;
	d[2][2] = 7;
	Matrix D = Matrix(3, 3);
	D.build(d);

	bool errorFlag = false;
	char select1, select2, select3;
	Matrix selectedA = Matrix(3, 3);
	Matrix selectedB = Matrix(3, 3);
	Matrix output = Matrix(3, 3);
	do
	{
		errorFlag = false;

		cout << "Select the first matrix (A,B,C,D): ";
		cin >> select1;
		switch (select1)
		{
			case 'A':
			case 'a':
				selectedA = A;
				break;
			case 'B':
			case 'b':
				selectedA = B;
				break;
			case 'C':
			case 'c':
				selectedA = C;
				break;
			case 'D':
			case 'd':
				selectedA = D;
				break;
			default:
				cout << "Invalid Selection!" << endl;
				errorFlag = true;
				continue;
		}

		cout << "Select the second matrix (A,B,C,D): ";
		cin >> select2;
		switch (select2)
		{
			case 'A':
			case 'a':
				selectedB = A;
				break;
			case 'B':
			case 'b':
				selectedB = B;
				break;
			case 'C':
			case 'c':
				selectedB = C;
				break;
			case 'D':
			case 'd':
				selectedB = D;
				break;
			default:
				cout << "Invalid Selection!" << endl;
				errorFlag = true;
				continue;
		}

		cout << "Do you want to add or multiply them (A,M): ";
		cin >> select3;
		switch (select3)
		{
			case 'A':
			case 'a':
				try
				{
					output = selectedA + selectedB;
				}
				catch (std::exception ex)
				{
					cout << "Can not add these matricies!" << endl;
					errorFlag = true;
					continue;
				}
				break;
			case 'M':
			case 'm':
				try
				{
					output = selectedA * selectedB;
				}
				catch (std::exception ex)
				{
					cout << "Can not multiply these matricies!" << endl;
					errorFlag = true;
					continue;
				}
				break;
			default:
				cout << "Invalid Selection!" << endl;
				errorFlag = true;
				continue;
		}
	} while (errorFlag);

	cout << "The selected Matrices are: " << endl;
	selectedA.display();
	cout << endl << "------------------- AND ---------------------" << endl;
	selectedB.display();
	cout << endl << "The selected output is: " << endl;
	output.display();
}

void MontyHallProblem()
{
	MontyHall::OutputTestResults();
}


void PermutationsAndCombinations()
{
	string inputn, inputr;
	unsigned long n, r;
	cin.ignore();

	cout << "Please fill out the following information with int values <= 10" << endl;
	cout << "What is the number of n: ";
	cin >> inputn;
	cout << "What is the number of r: ";
	cin >> inputr;

	cout << "---------------------------" << endl;

	if (IsNumeric(inputn) && IsNumeric(inputr))
	{
		n = std::stoul(inputn);
		r = std::stoul(inputr);

		if (n > 10 || r > 10)
		{
			cout << "Please input values <= 10 for n and r!" << endl;
			return;
		}
		else if (r > n)
		{
			cout << "r must not be greater than n!" << endl;
			return;
		}
		
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

