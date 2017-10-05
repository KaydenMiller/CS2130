#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CompStructs/BaseConverter.h"
#include <string>

using CompStructs::BaseConverter;
using std::string;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(BaseConversionTests)
{
	TEST_METHOD(BinaryValues)
	{
		int index = 0;
		string strexp = "1000";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToBinary(8).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "111";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToBinary(7).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "1";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToBinary(1).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "0";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToBinary(0).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "1111";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToBinary(15).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}
	}

	TEST_METHOD(Oct)
	{
		int index = 0;
		string strexp = "10";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToOct(8).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "1";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToOct(1).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "7";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToOct(7).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "11";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToOct(9).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "0";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToOct(0).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}
	}

	TEST_METHOD(HexNonAlpha)
	{

		int index = 0;
		string strexp = "0";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(0).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "1";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(1).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "8";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(8).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "10";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(16).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "11";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(17).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}
	}

	TEST_METHOD(HexAlpha)
	{
		int index = 0;
		string strexp = "A";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(10).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "B";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(11).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "C";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(12).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "D";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(13).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "E";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(14).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}

		index = 0;
		strexp = "F";
		for (char exp : strexp)
		{
			char q = BaseConverter::ToHex(15).at(index);
			bool out = (exp == q);
			Assert::AreEqual(exp, q);
			index++;
		}
	}
};