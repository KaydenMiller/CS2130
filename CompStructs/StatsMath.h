#pragma once

namespace CompStructs
{
	static class StatsMath
	{
	public:
		static unsigned long long Combination(unsigned long long n, unsigned long long r, bool repeat);
		static unsigned long long Permutation(unsigned long long n, unsigned long long r, bool repeat);
		static unsigned long long Factorial(unsigned long long n);
	};
}


