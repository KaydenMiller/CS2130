#pragma once
#include <string>

using std::string;

namespace CompStructs
{
	static class Hasher
	{
	public:
		static int HashString(string stringToHash);
	};
}