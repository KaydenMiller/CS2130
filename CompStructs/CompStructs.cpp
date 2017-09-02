// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"
#include <list>

using namespace std;

void ArrayTest()
{
	// an array with 5 elements.
	double balance[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	double *p;

	p = balance;

	// output each array element's value 
	cout << "Array values using pointer " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}


	cout << "Array values using balance as address " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "*(balance + " << i << ") : ";
		cout << *(balance + i) << endl;
	}
}

list<int> SubtractSets(list<int> A, list<int> B)
{
	list<int> temp = A;

	for (int numA : temp)
		for (int numB : B)
			temp.remove(numB);

	return temp;
}

int main()
{
	list<int> setA = { 1, 3, 5, 6, 8 };
	list<int> setB = { 2, 3, 4, 7, 9 };
	
	cout << "Subtract: ";
	for (int num : SubtractSets(setA, setB))
		cout << num << " ";
	cout << endl << "---------------------------" << endl;

	int input;
	std::cin >> input;
    return 0;
}