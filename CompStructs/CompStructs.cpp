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

int main()
{
	list<int> setA = { 1, 3, 5, 6, 8 };
	list<int> setB = { 2, 3, 4, 7, 9 };
	string inputString;
	
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

	cout << "Please Input a sentence to be hashed: ";
	std::getline(cin, inputString);
	cout << "Hashed String Value: " << Hasher::HashString(inputString);
	cout << endl << "---------------------------" << endl;

	int input;
	std::cin >> input;
    return 0;
}