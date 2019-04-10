#include <iostream>
#include "Circle.h"

using namespace std;

int main(void)
{
	char op;
	Circle<double> a;
	Circle<double> b;
	cout << "Circle test program\n";
	cout << "oparand A: ";
	cin >> a;
	cout << "oparand B: ";
	cin >> b;

	cout << "\nOperand A:\n" << a;
	cout << "Perimeter: " << a.perimeter();
	cout << " Area: " << a.area() << "\n\n";
	cout << "Operand B:\n" << b;
	cout << "Perimeter: " << b.perimeter();
	cout << " Area: " << b.area() << "\n\n";

	if (a > b) cout << "A > B\n";
	else if (a == b) cout << "A = B\n";	
	else if (a < b) cout << "A < B\n";

	cout << "\nOperation (+/-): ";
	cin >> op;

	switch (op)
	{
		case '+': a++; break;
		case '-': a--; break;
	}

	cout << "Result:\n" << a << "\n";
	system("pause");
	return EXIT_SUCCESS;
}