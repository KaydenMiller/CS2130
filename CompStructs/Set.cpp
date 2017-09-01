#include "stdafx.h"
#include "Set.h"
#include <stdlib.h>

Set::Set(int set[], int size)
{
	elements = set;
	length = size;
}

int Set::Length()
{
	return length;
}

Set Set::operator-(const Set& B)
{
	int size = (this->Length() + B.length);
	//temp[size] = elements;
	//temp = elements;
	
	for (int elementB = 0; elementB < B.length; elementB++)
	{
		bool sameElemFlag = false;

		for (int elementA = 0; elementA < this->length; elementA++)
		{
			if (this->elements[elementA] == B.elements[elementB])
				sameElemFlag = true;
		}

		if (!sameElemFlag)
			temp[this->length + elementB + 1] = B.elements[elementB];
	}

	return Set(temp, *(&temp + 1) - temp);
}

std::ostream& operator<<(std::ostream& os, Set& A)
{
	for (int i = 0; i < A.Length(); i++)
	{
		os << A.elements[i];
	}

	return os;
}