#include "stdafx.h"
#include "Set.h"
#include <stdlib.h>
#include <list>

using std::list;

Set::Set(list<int> input)
{
	set = input;
}

list<int> Set::GetList()
{
	return set;
}

Set Set::Union(Set& A, Set& B)
{
	list<int> temp = A.GetList();
	temp.merge(B.GetList());
	temp.unique();

	return Set(temp);
}

Set Set::Intersection(Set& A, Set& B)
{
	list<int> temp;
	list<int> setA = A.GetList();
	list<int> setB = B.GetList();

	for (list<int>::iterator itA = setA.begin(); itA != setA.end(); itA++)
	{
		for (list<int>::iterator itB = setB.begin(); itB != setB.end(); itB++)
		{
			if (*itA == *itB)
				temp.push_back(*itA);
		}
	}

	return Set(temp);
}

Set Set::operator-(Set& B)
{
	list<int> temp = this->set;

	for (int numA : temp)
		for (int numB : B.GetList())
			temp.remove(numB);

	return Set(temp);
}

std::ostream& operator<<(std::ostream& os, Set& A)
{
	for (int num : A.GetList())
		os << num << " ";

	return os;
}