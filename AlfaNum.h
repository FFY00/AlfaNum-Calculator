#pragma once

#include <iostream>
#include <string>

using namespace std;

class AlfaNum {
private:
		string numString;

public:
		AlfaNum();
		string getString();
		friend ostream& operator<< (ostream &out, const AlfaNum &num);
		friend istream& operator>> (istream &in, AlfaNum &num);
		friend AlfaNum operator+ (const AlfaNum &num1, const AlfaNum &num2);
		friend AlfaNum operator- (const AlfaNum &num1, const AlfaNum &num2);
		friend AlfaNum operator* (AlfaNum &num1, AlfaNum &num2);
		friend AlfaNum operator/ (const AlfaNum &num1, const AlfaNum &num2);

};