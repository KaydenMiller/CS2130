#include "stdafx.h"
#include <iostream>
#include <exception>

using std::exception;

namespace CompStructs
{
	class InvalidValueException : public exception
	{
		virtual const char* what() const throw()
		{
			return "An Invalid Value Exception happend";
		}
	};
}