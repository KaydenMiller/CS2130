#pragma once
#include <iostream>

/*
	Section 1.1 1.2

	Hardcode 2 sets of 5 integers 
		A = {1, 3, 5, 6, 8}
		B = {2, 3, 4, 7, 9}
	Compute A Union B, A Intersection B, A - B
	Display the answers in common set notation
*/
class Set
{
public:
	Set(int set[], int size);

	int Length();
	Set Union (Set& A, Set& B);
	Set Intersection(Set& A, Set& B);
	Set operator-(const Set& B);
	friend std::ostream& operator<<(std::ostream& os, const Set& A);


	int* elements;
private:
	int *temp;
	int length;
};