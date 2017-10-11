#pragma once
#include <string>

using std::string;

namespace CompStructs
{
	static class TruthTableBuilder
	{
	private:
		string AND_or_OR = "AND";
		bool NOTp = false;
		bool NOTq = false;

		void Question1();
		void Question2();
		void Question3();
		string ToLower(string input);
	public:
		void AskQuestions();
	};
}
