#include "AlfaNum.h"

char addChar(char char1, char char2, int &carry) {
	char result;
	result = char((char1-48) + (char2-48) + carry);
	carry = 0;
	if (result > 57)
	{
		carry = result - 57;
		result = char(carry + 48);
	}
	return result;
}

ostream & operator<<(ostream & out, const AlfaNum & num) {
	out << num.numString;

	return out;
}

istream & operator >> (istream & in, AlfaNum & num) {
	in >> num.numString;
	
	return in;
}

AlfaNum & operator+(AlfaNum & num1, AlfaNum & num2) {
	AlfaNum result;
	result.numString = "0000";
	int carry = 0;
	if (num1.numString.length() > num2.numString.length())
	{
		for (unsigned int i = 0; i < num1.numString.length(); i++)
		{
			result.numString.at(i) = addChar(num1.numString.at(i), num2.numString.at(i), carry);
		}
	}

	return result;
}

AlfaNum::AlfaNum() {
	numString = "0";
}
