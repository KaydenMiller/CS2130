#pragma once
#include <iostream>
#include <list>

using std::list;

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
	Set(list<int> input);

	list<int> GetList();

	static Set Union (Set& A, Set& B);
	static Set Intersection(Set& A, Set& B);
	Set operator-(Set& B);
	friend std::ostream& operator<<(std::ostream& os, Set& A);

private:
	list<int> set;
};