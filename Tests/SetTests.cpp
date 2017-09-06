#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CompStructs/Set.h"
#include <list>

using std::list;
using CompStructs::Set;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/* 
	"expected a string literal, but found a user-defined string literal instead"
	this error is preventing compilation of the Test solution
	has something to do with not being able to use custom types
*/
namespace Tests
{		
	TEST_CLASS(SetTests)
	{
	public:
		
		TEST_METHOD(GettingListFromSet)
		{
			list<int> listA = { 1, 2, 3, 4, 5 };
			Set A = Set(listA);

			for (int numA : A.GetList())
			{
				bool flag = false;

				for (int exp : listA)
				{
					if (numA == exp)
					{
						flag = true;
						Assert::AreEqual(exp, numA);
						break;
					}
				}
				
				if (!flag)
					Assert::Fail();
			}
		}

		TEST_METHOD(SubtractionOnSets)
		{
			list<int> listA = { 1, 2, 3, 4, 5 };
			list<int> listB = { 0, 2, 3, 8, 9 };
			Set A = Set(listA);
			Set B = Set(listB);

			list<int> expected = { 1, 4, 5 };
			//list<int> output = (A - B).GetList();
			for (int num : expected)
			{
				bool flag = false;

				for (int exp : expected)
				{
					if (num == exp)
					{
						flag = true;
						Assert::AreEqual(exp, num);
						break;
					}
				}

				if (!flag)
					Assert::Fail();
			}
		}
	};
}