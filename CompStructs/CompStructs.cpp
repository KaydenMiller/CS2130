// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"
#include <list>

using std::cout;
using std::endl;
using std::list;

void SubtractSets(list<int> A, list<int> B)
{
	list<int> temp = A;

	for (int numA : temp)
		for (int numB : B)
			temp.remove(numB);

	cout << "Subtract: ";
	for (int num : temp)
		cout << num << " ";
	cout << endl << "---------------------------" << endl;
}

void UnionOfSets(list<int> A, list<int> B)
{
	list<int> temp = A;		// set temp equal to A
	temp.merge(B);			// merge B into the temp
	temp.unique();			// Remove all duplicate values

	cout << "Union: ";
	for (int num : temp)
		cout << num << " ";
	cout << endl << "---------------------------" << endl;
}

void IntersectionOfSets(list<int> A, list<int> B)
{
	list<int> temp;

	for (list<int>::iterator itA = A.begin(); itA != A.end(); itA++)
	{
		for (list<int>::iterator itB = B.begin(); itB != B.end(); itB++)
		{
			if (*itA == *itB)
				temp.push_back(*itA);
		}
	}

	cout << "Intersection: ";
	for (int num : temp)
		cout << num << " ";
	cout << endl << "---------------------------" << endl;
}

int main()
{
	list<int> setA = { 1, 3, 5, 6, 8 };
	list<int> setB = { 2, 3, 4, 7, 9 };
	
	
	SubtractSets(setA, setB);
	UnionOfSets(setA, setB);
	IntersectionOfSets(setA, setB);

	int input;
	std::cin >> input;
    return 0;
}