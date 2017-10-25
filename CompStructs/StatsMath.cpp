#include "stdafx.h"
#include "StatsMath.h"
#include <cmath>

namespace CompStructs
{
	long StatsMath::Combination(long n, long r, bool repeat)
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

	long StatsMath::Permutation(long n, long r, bool repeat)
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

	long StatsMath::Factorial(long n)
	{
		if (n > 1)
			return n * Factorial(n - 1);
		else
			return 1;
	}
}