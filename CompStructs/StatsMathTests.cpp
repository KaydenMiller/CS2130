#include "stdafx.h"
#include "../CompStructs/StatsMath.h"
#include "CppUnitTest.h"

using CompStructs::StatsMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(PermutationTests)
	{
		TEST_METHOD(WithoutRepeats_n10)
		{
			Assert::AreEqual((unsigned long long)10, StatsMath::Permutation(10, 1, false));
			Assert::AreEqual((unsigned long long)90, StatsMath::Permutation(10, 2, false));
			Assert::AreEqual((unsigned long long)30240, StatsMath::Permutation(10, 5, false));
			Assert::AreEqual((unsigned long long)1814400, StatsMath::Permutation(10, 8, false));
			Assert::AreEqual((unsigned long long)3628800, StatsMath::Permutation(10, 9, false));
			Assert::AreEqual((unsigned long long)3628800, StatsMath::Permutation(10, 10, false));
		}

		TEST_METHOD(WithRepeats_n10)
		{
			Assert::AreEqual((unsigned long long)10000, StatsMath::Permutation(10, 4, true));
			Assert::AreEqual((unsigned long long)100000, StatsMath::Permutation(10, 5, true));
			Assert::AreEqual((unsigned long long)1000000, StatsMath::Permutation(10, 6, true));
			Assert::AreEqual((unsigned long long)10000000, StatsMath::Permutation(10, 7, true));
			Assert::AreEqual((unsigned long long)100000000, StatsMath::Permutation(10, 8, true));
			Assert::AreEqual((unsigned long long)1000000000, StatsMath::Permutation(10, 9, true));
			Assert::AreEqual((unsigned long long)10000000000, StatsMath::Permutation(10, 10, true));
		}
	};

	TEST_CLASS(CombinationTests)
	{
		TEST_METHOD(WithoutRepeats_n5)
		{
			Assert::AreEqual((unsigned long long)5, StatsMath::Combination(5, 1, false));
			Assert::AreEqual((unsigned long long)10, StatsMath::Combination(5, 2, false));
			Assert::AreEqual((unsigned long long)10, StatsMath::Combination(5, 3, false));
			Assert::AreEqual((unsigned long long)5, StatsMath::Combination(5, 4, false));
			Assert::AreEqual((unsigned long long)1, StatsMath::Combination(5, 5, false));
		}

		TEST_METHOD(WithoutRepeats_n10)
		{
			Assert::AreEqual((unsigned long long)10, StatsMath::Combination(10, 1, false));
			Assert::AreEqual((unsigned long long)45, StatsMath::Combination(10, 2, false));
			Assert::AreEqual((unsigned long long)252, StatsMath::Combination(10, 5, false));
			Assert::AreEqual((unsigned long long)45, StatsMath::Combination(10, 8, false));
			Assert::AreEqual((unsigned long long)10, StatsMath::Combination(10, 9, false));
		}

		TEST_METHOD(WithRepeats)
		{
			Assert::AreEqual((unsigned long long)10, StatsMath::Combination(10, 1, true));
			Assert::AreEqual((unsigned long long)220, StatsMath::Combination(10, 3, true));
			Assert::AreEqual((unsigned long long)2002, StatsMath::Combination(10, 5, true));
			Assert::AreEqual((unsigned long long)92378, StatsMath::Combination(10, 10, true));
		}
	};

	TEST_CLASS(FactorialTests)
	{
		TEST_METHOD(Return1When0)
		{
			Assert::AreEqual((unsigned long long)1, StatsMath::Factorial(0));
		}

		TEST_METHOD(OutputTrough8)
		{
			Assert::AreEqual((unsigned long long)1, StatsMath::Factorial(1));
			Assert::AreEqual((unsigned long long)2, StatsMath::Factorial(2));
			Assert::AreEqual((unsigned long long)6, StatsMath::Factorial(3));
			Assert::AreEqual((unsigned long long)24, StatsMath::Factorial(4));
			Assert::AreEqual((unsigned long long)120, StatsMath::Factorial(5));
			Assert::AreEqual((unsigned long long)720, StatsMath::Factorial(6));
			Assert::AreEqual((unsigned long long)5040, StatsMath::Factorial(7));
			Assert::AreEqual((unsigned long long)40320, StatsMath::Factorial(8));
		}

		TEST_METHOD(OutputFrom9To12)
		{
			Assert::AreEqual((unsigned long long)362880, StatsMath::Factorial(9));
			Assert::AreEqual((unsigned long long)3628800, StatsMath::Factorial(10));
			Assert::AreEqual((unsigned long long)39916800, StatsMath::Factorial(11));
			Assert::AreEqual((unsigned long long)479001600, StatsMath::Factorial(12));
		}
	};
}