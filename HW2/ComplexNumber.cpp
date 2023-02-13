// Authors: Keith A. Shomper, Alexander Taylor
// Date:	7 January 2020
//			16 January 2023
// Purpose: Class implementation for ComplexNumber
//			in CS-1220 HW2

#include <cstdio>
#include <cstring>
#include <string>
#include <regex>
#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(float real, float imag)
{
	r = real;
	i = imag;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs)
{
	r = rhs.r;
	i = rhs.i;
}

// Constructor to take a string and parse a complex number from it
ComplexNumber::ComplexNumber(const char* number)
{
	// Regex for grabbing the complex number from the input string
	std::cmatch complexNumber;
	std::regex_search(number, complexNumber, std::regex(
		// Real part
		// Make sure that there's actually a number in the string
		"^(?=[i.\\d+-])"
		// Match the whole and decimal part of the real number
		"([+-]?(?:\\d+(?:\\.\\d*)?|\\.\\d+)"
		// Match the exponential part of the real number
		"(?:e[+-]?\\d+)?"
		// Negative lookahead so that it doesn't match imaginary
		"(?![i.\\d]))?"

		// Imaginary part
		// Match the whole and decimal part of the imaginary number
		"([+-]?(?:(?:\\d+(?:\\.\\d*)?|\\.\\d+)"
		// Match the exponential part of the imaginary number
		"(?:e[+-]?\\d+)?)?"
		// Make sure we have an i so that it's imaginary
		"i)?$"
	));
	std::string realString = complexNumber[1].str();
	std::string imaginaryString = complexNumber[2].str();
	if (realString == "")
	{
		r = 0;
	}
	else
	{
		// No need for exception catching here since the regex 
		// will always yield a number
		r = std::stof(realString);
	}
	if (imaginaryString == "-i")
	{
		i = -1;
	}
	else if (imaginaryString == "+i" || imaginaryString == "i")
	{
		i = 1;
	}
	else if (imaginaryString == "")
	{
		i = 0;
	}
	else
	{
		// No need for exception catching here since the regex 
		// will always yield a number
		i = std::stof(imaginaryString);
	}
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs)
{
	r = rhs.r;
	i = rhs.i;
	return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhs)
{
	return ComplexNumber(
		// Real part
		this->r * rhs.r - this->i * rhs.i,
		// Imaginary part
		(this->r + this->i) * (rhs.r + rhs.i) -
		this->r * rhs.r - this->i * rhs.i
	);
}

bool ComplexNumber::operator==(const ComplexNumber& rhs) const
{
	return (r == rhs.r && i == rhs.i);
}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b)
{
	ComplexNumber result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;

	return result;
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b)
{
	ComplexNumber result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;

	return result;
}

ostream& operator<<(ostream& out, const ComplexNumber& b)
{
	bool rPrinted = false;

	if (b.r != 0 || (b.r == 0 && b.i == 0))
	{
		out << b.r;
		rPrinted = true;
	}

	if (b.i > 0)
	{
		if (rPrinted)
		{
			out << "+";
		}
		if (b.i != 1)
		{
			out << b.i;
		}
		out << "i";
	}
	else if (b.i < 0)
	{
		if (b.i == -1)
		{
			out << "-";
		}
		else
		{
			out << b.i;
		}
		out << "i";
	}

	return out;
}

istream& operator>>(istream& in, ComplexNumber& b)
{
	std::string inputNumber;
	in >> inputNumber;

	b = ComplexNumber(inputNumber.c_str());

	return in;
}
