#include <string>
#include <iostream>
#include "AlfaNum.h"
#include <time.h>
#include <ctime>

using namespace std;

int main() {
	AlfaNum num1, num2;
	unsigned long long n1, n2;
	cout << "Introduz o primeiro numero" << endl;
	cin >> num1;
	cout << "intruduz o segundo numero" << endl;
	cin >> num2;

	//test time
	clock_t    start;
	start = clock();
	cout << num1 * num2 << endl;
	cout << "Time: " << (clock() - start) << " clocks" << endl;


	return 0;
}