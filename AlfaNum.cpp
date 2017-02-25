#include "AlfaNum.h"
#include <algorithm>

char addChar(const char char1,const char char2, char &carry) {
	char result;
	result = char((char1-48) + char2 + (carry-48));
	carry = '0';
	if (result > 57)
	{
		carry = '1';
		result -= 10;
	}
	return result;
}

char subChar(const char char1,const char char2, char &carry) {
	char result;
	if (carry == '1')
	{
		if (char1 + 1 >= char2)
		{
			result = char(char1 - (char2 + 1) + 48);
			carry = '0';
		}
		else
		{
			result = char(char1 + 10 - (char2 + 1) + 48);
			carry = '1';
		}
	}
	else
	{
		if (char1 >= char2)
		{
			result = char(char1 - char2 + 48);
			carry = '0';
		}
		else
		{
			result = char(char1 + 10 - char2 + 48);
			carry = '1';
		}
	}
	return result;
}

ostream & operator<< (ostream & out, const AlfaNum & num) {
	out << num.numString;

	return out;
}

istream & operator>> (istream & in, AlfaNum & num) {
	in >> num.numString;
	
	return in;
}

AlfaNum operator+(const AlfaNum &num1, const AlfaNum &num2) {
	char carry = '0';
	if (num1.numString.length() < num2.numString.length())
	{
		int length = num2.numString.length() - 1;
		AlfaNum result = num2;
		for (int i = num1.numString.length() - 1; i >= 0; i--)
		{
			result.numString.at(length) = addChar(num2.numString.at(length), num1.numString.at(i), carry);
			length--;
		}
		if (carry != '0')
		{
			result.numString.at(length) = addChar(num2.numString.at(length), 0, carry);
		}
		return result;
	}
	else if (num1.numString.length() > num2.numString.length())
	{
		int length = num1.numString.length() - 1;
		AlfaNum result = num1;
		for (int i = num2.numString.length() - 1; i >= 0; i--)
		{
			result.numString.at(length) = addChar(num1.numString.at(length), num2.numString.at(i), carry);
			length--;
		}
		if (carry != '0')
		{
			result.numString.at(length) = addChar(num1.numString.at(length), 0, carry);
		}
		return result;
	}
	else
	{
		AlfaNum result = num1;
		for (int i = num1.numString.length() - 1; i >= 0; i--)
		{
			result.numString.at(i) = addChar(num1.numString.at(i), num2.numString.at(i), carry);
		}
		if (carry != '0')
		{
			result.numString.insert(0, 1, carry);
		}
		return result;
	}
}

AlfaNum operator-(const AlfaNum & num1, const AlfaNum & num2) {
	char carry = '0';
	if (num1.numString.length() > num2.numString.length())
	{
		AlfaNum result = num1;
		int length = num1.numString.length() - 1;
		for (int i = num2.numString.length() - 1; i >= 0; i--)
		{
			result.numString.at(length) = subChar(num1.numString.at(length), num2.numString.at(i), carry);
			length--;
		}
		while (carry != '0' && length >= 0)
		{
			result.numString.at(length) = subChar(result.numString.at(length), 0, carry);
			length--;
		}
		return result;
	}
	else if(num1.numString.length() < num2.numString.length())
	{
		AlfaNum result = num2;
		int length = num2.numString.length() - 1;
		for (int i = num1.numString.length() - 1; i >= 0; i--)
		{
			result.numString.at(length) = subChar(num2.numString.at(length), num1.numString.at(i), carry);
			length--;
		}
		while (carry != '0' && length >= 0)
		{
			result.numString.at(length) = subChar(result.numString.at(length), 0, carry);
			length--;
		}
		result.numString.insert(0, 1, '-');
		return result;
	}
	else
	{
		AlfaNum result = num1;
		for (int i = num1.numString.length() - 1; i >= 0 ; i--)
		{
			result.numString.at(i) = subChar(num1.numString.at(i), num2.numString.at(i), carry);
		}
		if (carry != '0')
		{
			result.numString.insert(0, 1, carry);
			result.numString.insert(0, 1, '-');
		}
		return result;
	}
}

AlfaNum operator*(AlfaNum & num1, AlfaNum & num2) {
	AlfaNum result;
	char carry = '0';
	char carryMul = '0';

	//reverse number for easy calculation
	reverse(num1.numString.begin(), num1.numString.end());
	reverse(num2.numString.begin(), num2.numString.end());

	for (size_t i = 0; i < num2.numString.length(); i++)
	{
		for (size_t k = 0; k < num1.numString.length(); k++)
		{
			for (char j = '0'; j < num2.numString.at(i); j++)
			{
				while (i+k >= result.numString.length())
				{
					result.numString.append("0");
				}
				result.numString.at(i + k) = addChar(result.numString.at(i + k), num1.numString.at(k), carry);
				if (carry != '0')
				{
					carryMul++;
					carry = '0';
				}
			}
			if (carryMul != '0')
			{
				while (i + k > result.numString.length())
				{
					result.numString.append("0");
				}
				if (i + k + 1 == result.numString.length())
				{
					result.numString.append(1, carryMul);
					carryMul = '0';
				}
				else
				{
					result.numString.at(i + k + 1) = addChar(result.numString.at(i + k + 1), carryMul, carry);
					carryMul = '0';
					int index = 2;
					while (carry != '0')
					{
						if (i + k + index >= result.numString.length())
						{
							result.numString.append(1, '1');
							carry = '0';
						}
						else
						{
							carry = '0';
							result.numString.at(i + k + index) = addChar(result.numString.at(i + k + index), '1', carry);
						}
						index++;
					}
				}
			}
		}
	}

	//reverse again for number reset to real order
	reverse(num1.numString.begin(), num1.numString.end());
	reverse(num2.numString.begin(), num2.numString.end());
	reverse(result.numString.begin(), result.numString.end());
	
	return result;
}

AlfaNum operator/(const AlfaNum & num1, const AlfaNum & num2) {
	AlfaNum result;
	// TODO: insert return statement here
	return result;
}

AlfaNum::AlfaNum() {
	numString = "0";
}

string AlfaNum::getString() {
	return this->numString;
}
