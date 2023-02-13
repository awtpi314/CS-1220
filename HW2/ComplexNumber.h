// Authors: Keith A. Shomper, Alexander Taylor
// Date:    7 January 2020
//			16 January 2023
// Purpose:	Header file for CS-1220 HW 2

#include <iostream>

using namespace std;

class ComplexNumber
{
public:
	// Constructors
	ComplexNumber(float real = 0.0, float imag = 0.0);
	ComplexNumber(const ComplexNumber &rhs);
	ComplexNumber(const char *number);

	ComplexNumber &operator=(const ComplexNumber &rhs);
	ComplexNumber operator*(const ComplexNumber &);

	// Equality operator needed for unit test in HW2
	bool operator==(const ComplexNumber &rhs) const;

	// Friend operator functions
	friend ComplexNumber operator+(const ComplexNumber &, const ComplexNumber &);
	friend ComplexNumber operator-(const ComplexNumber &, const ComplexNumber &);
	friend ostream &operator<<(ostream &, const ComplexNumber &);
	friend istream &operator>>(istream &, ComplexNumber &);

	// Data members
private:
	float r;
	float i;
};
