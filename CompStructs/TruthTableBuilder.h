#pragma once
#include <string>

using std::string;

namespace CompStructs
{
	// V = or, A = and, ~ = not
	class TruthTableBuilder
	{
	private:
		bool AND = false;
		bool OR = false;
		bool NOTp = false;
		bool NOTq = false;

		void Question1();
		void Question2();
		void Question3();
		string ToLower(string input);
		string BuildPropStatement();
		string GetLogicalEquivalent(unsigned char input);
		string GetLogicalEquivalent(bool input);
	public:
		void AskQuestions();
		void OutputTable();
		void OutputLargeTable();
	};
}
