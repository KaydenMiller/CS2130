#pragma once
#include <string>

using std::string;

namespace CompStructs
{
	static class BaseConverter
	{
	public:
		static string ToBinary(int num);
		static string ToHex(int num);
		static string ToOct(int num);

	private:
		static const int BIN = 2;
		static const int OCT = 8;
		static const int HEX = 16;
	};
}