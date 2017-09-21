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
		TEST_METHOD(HashStringWithMod31)
		{
			string input1 = "I am very hungry";
			string input2 = "Hello my name is Kayden";
			string input3 = "This is a test";

			Assert::AreEqual(1, Hasher::HashString(input1));
			Assert::AreEqual(-21, Hasher::HashString(input2));
			Assert::AreEqual(-21, Hasher::HashString(input3));
		}
	};
}