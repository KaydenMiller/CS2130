#pragma once
static class BaseConverter
{
public:
	static void ToBinary(int num);
	static void ToHex(int num);
	static void ToOct(int num);

private:
	static const int BIN = 2;
	static const int OCT = 8;
	static const int HEX = 16;
};

