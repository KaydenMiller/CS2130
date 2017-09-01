// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"

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

void SubtractSets(int* a, const int sizeA, int* b, const int sizeB)
{
	int temp[10];

	// Merge Values
	for (int i = 0; i < sizeA; i++)
		temp[i] = a[i];

	for (int i = 0; i < sizeB; i++)
		temp[i + sizeA] = b[i];

	// Remove Duplicates
	for (int i = 0; i < 10; i++)
	{
		int testAgainst = *(temp + i);
		for (int j = 0; i < 10 - 1; i++)
		{
			if (temp[j] == testAgainst)
			{
				temp[j] = NULL;
			}
		}
	}

	cout << "Temp: ";
	for (int i = 0; i < 10; i++)
	{
		cout << *(temp + i) << " ";
	}
	cout << endl;
}

int main()
{
	int setA[] = { 1, 3, 5, 6, 8 };
	int setB[] = { 2, 3, 4, 7, 9 };

	int* a = setA;
	int* b = setB;
	SubtractSets(a, 5, b, 5);


	//Set *A = new Set(setA, *(&setA + 1) - setA);
	//Set *B = new Set(setB, *(&setB + 1) - setB);

	//Set C = *A - *B;
	//Add(&x, &y);
	//ArrayTest();

	//std::cout << "A - B: " << (A - B);

	//SubtractSets(setA, 5, setB, 5);

	int input;
	std::cin >> input;
    return 0;
}