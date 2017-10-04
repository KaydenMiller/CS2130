#include "stdafx.h"
#include "BaseConverter.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace CompStructs
{
	string BaseConverter::ToBinary(int num)
	{
		vector<char> output;

		vector<char>::iterator frontIt = output.begin();

		output.insert(frontIt, num % BIN);
		int temp = num / BIN;
		while (temp != 0)
		{
			frontIt = output.begin();
			output.insert(frontIt, temp % BIN);
			temp /= BIN;
		}

		string newOutput;
		for (vector<char>::iterator it = output.begin(); it != output.end(); it++)
		{
			newOutput.append(std::to_string(*it));
		}

		return newOutput;
	}

	string BaseConverter::ToOct(int num)
	{
		vector<char> output;

		vector<char>::iterator frontIt = output.begin();

		output.insert(frontIt, num % OCT);
		int temp = num / OCT;
		while (temp != 0)
		{
			frontIt = output.begin();
			output.insert(frontIt, temp % OCT);
			temp /= OCT;
		}

		string newOutput;
		for (vector<char>::iterator it = output.begin(); it != output.end(); it++)
		{
			newOutput.append(std::to_string(*it));
		}

		return newOutput;
	}


	string HexCharacterConverter(int value)
	{
		switch (value)
		{
			case 10:
				return "A";
			case 11:
				return "B";
			case 12:
				return "C";
			case 13:
				return "D";
			case 14:
				return "E";
			case 15:
				return "F";
		}
	}

	string BaseConverter::ToHex(int num)
	{
		vector<string> output;

		vector<string>::iterator frontIt = output.begin();

		output.insert(frontIt, ((num % HEX) >= 10) ? HexCharacterConverter(num % HEX) : std::to_string((num % HEX)));
		int temp = num / HEX;
		while (temp != 0)
		{
			frontIt = output.begin();
			output.insert(frontIt, ((temp % HEX) >= 10) ? HexCharacterConverter(temp % HEX) : std::to_string((temp % HEX)));
			temp /= HEX;
		}

		string newOutput;
		for (vector<string>::iterator it = output.begin(); it != output.end(); it++)
		{
			newOutput.append(*it);
		}

		return newOutput;
	}
}