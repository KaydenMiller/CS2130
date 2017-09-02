#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CompStructs/Set.h"
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::list;


/* 
	"expected a string literal, but found a user-defined string literal instead"
	this error is preventing compilation of the Test solution
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

			Assert::AreEqual(listA, A.GetList());
		}

		TEST_METHOD(SubtractionOnSets)
		{
			list<int> listA = { 1, 2, 3, 4, 5 };
			list<int> listB = { 0, 2, 3, 8, 9 };
			Set A = Set(listA);
			Set B = Set(listB);

			list<int> correctList = { 1, 4, 5 };
			Assert::AreEqual(correctList, (A - B).GetList());
		}
	};
}