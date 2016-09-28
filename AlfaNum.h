#pragma once

#include <iostream>
#include <string>

using namespace std;

class AlfaNum {
private:
		string numString;

public:
		AlfaNum();
		friend ostream& operator<<(ostream& out, const AlfaNum & num);
		friend istream& operator >> (istream& in, AlfaNum & num);
		friend AlfaNum& operator+(AlfaNum &num1, AlfaNum &num2);

};