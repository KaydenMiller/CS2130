#include "stdafx.h"
#include "Set.h"
#include <stdlib.h>
#include <list>
#include <string>

using std::list;
using std::string;

namespace CompStructs
{
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

	string Set::ToString()
	{
		list<int> setA = this->GetList();
		list<int>::iterator end = setA.end();
		end--;
		string output;

		output.append("{ ");
		for (list<int>::iterator it = setA.begin(); it != setA.end(); it++)
		{
			if (it == end)
				output.append(std::to_string(*it) + " }");
			else
				output.append(std::to_string(*it) + ", ");
		}

		return output;
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
		string output = A.ToString();
		os << output;
		return os;

		/*
		list<int> setA = A.GetList();
		list<int>::iterator end = setA.end();
		end--;

		os << "{ ";
		for (list<int>::iterator it = setA.begin(); it != setA.end(); it++)
		{
			if (it == end)
				os << *it << " }";
			else
				os << *it << ", ";
		}

		return os;
		*/
		
	}
}