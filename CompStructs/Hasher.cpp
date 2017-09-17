#include "stdafx.h"
#include "Hasher.h"
#include <string>

using std::string;

namespace CompStructs
{
	int Hasher::HashString(string stringToHash)
	{
		string lowerStringToHash;

		for (char c : stringToHash)
		{
			lowerStringToHash += tolower(c);
		}

		int stringValue = 0;
		for (char c : lowerStringToHash)
		{
			if (c == ' ')
			{
				stringValue += 31;
			}
			else
			{
				stringValue += c - 96;
			}
		}

		return (stringValue % 31);
	}
}