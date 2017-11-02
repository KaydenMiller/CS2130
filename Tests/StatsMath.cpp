#include "stdafx.h"
#include "../CompStructs/StatsMath.h"
#include <cmath>

namespace CompStructs
{
	unsigned long long StatsMath::Combination(unsigned long long n, unsigned long long r, bool repeat)
	{
		if (repeat)
		{
			return Factorial(n + r - 1) / (Factorial(r) * Factorial((n + r - 1) - r));
		}
		else
		{
			return Factorial(n) / (Factorial(r) * Factorial(n - r));
		}
	}

	unsigned long long StatsMath::Permutation(unsigned long long n, unsigned long long r, bool repeat)
	{
		if (repeat)
		{
			return std::pow(n, r);
		}
		else
		{
			return Factorial(n) / Factorial(n - r);
		}
	}

	unsigned long long StatsMath::Factorial(unsigned long long n)
	{
		if (n > 1)
			return n * Factorial(n - 1);
		else
			return 1;
	}
}