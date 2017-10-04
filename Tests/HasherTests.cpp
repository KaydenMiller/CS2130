#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CompStructs/Hasher.h"
#include <string>

using std::string;
using CompStructs::Hasher;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(HashingTests)
	{
		TEST_METHOD(StringsHaveCorrectValues)
		{
			Assert::AreEqual(0, Hasher::HashString("I am very hungry"));
			Assert::AreEqual(25, Hasher::HashString("Hello my name is Kayden"));
			Assert::AreEqual(25, Hasher::HashString("This is a test"));
			Assert::AreEqual(19, Hasher::HashString("bob"));
			Assert::AreEqual(19, Hasher::HashString("BOB"));
		}

		TEST_METHOD(UpperAndLowerCaseGiveSameValue)
		{
			Assert::AreEqual(Hasher::HashString("BOB"), Hasher::HashString("bob"));
		}
	};
}