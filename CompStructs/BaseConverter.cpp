#include "stdafx.h"
#include "BaseConverter.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void BaseConverter::ToBinary(int num)
{
	vector<char> output;

	vector<char>::iterator frontIt = output.begin();

	output.insert(frontIt, num % BIN);
	int temp = num / BIN;
	while (temp != 0)
	{
		output.insert(frontIt, temp % BIN);
		temp /= BIN;
	}

	for (char c : output)
	{
		cout << c;
	}
}

void BaseConverter::ToOct(int num)
{

}

void BaseConverter::ToHex(int num)
{

}