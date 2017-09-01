// CompStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Set.h"

void SubtractSets(int* A[], int, int* B[], int);

int main()
{
	int setA[] = { 1, 3, 5, 6, 8 };
	int setB[] = { 2, 3, 4, 7, 9 };

	//Set *A = new Set(setA, *(&setA + 1) - setA);
	//Set *B = new Set(setB, *(&setB + 1) - setB);

	//Set C = *A - *B;

	//std::cout << "A - B: " << (A - B);

	SubtractSets(setA, 5, setB, 5);

	int input;
	std::cin >> input;
    return 0;
}

void SubtractSets(int* A, int aSize, int* B, int bSize)
{
	std::cout << A << " : " << B << std::endl;
	int ASize = aSize;
	int BSize = bSize;

	for (int a = 0; a < ASize; a++)
	{
		std::cout << A;
	}

	std::cout << std::endl;

	for (int b = 0; b < BSize; b++)
	{
		std::cout << B;
	}
}