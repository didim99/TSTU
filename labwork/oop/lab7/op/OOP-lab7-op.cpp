#include "pch.h"
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(void)
{
	char op;
	int r, c;
	double v;

	cout << "Matrix test program\n";
    cout << "Rows: ";
	cin >> r;
	cout << "Columns: ";
	cin >> c;

	Matrix *pa = new Matrix(r, c);
	Matrix *pb = new Matrix(r, c);
	Matrix a = *pa, b = *pb;

	cout << "Operand A (" << r << "x" << c << "):\n";
	cin >> a;
	cout << "Operand B (" << r << "x" << c << "):\n";
	cin >> b;
	cout << "Operation (+/-/*): ";
	cin >> op;
	
	try {
		switch (op) {
		case '+': a = a + b; break;
		case '-': a = a - b; break;
		case '*': a = a * b; break;
		}
	} catch (const invalid_argument) {
		cout << "Impossible operation!\n";
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "A*B:\n" << a;
	cout << "Operation (+/-/*//): ";
	cin >> op;
	cout << "Value: ";
	cin >> v;

	switch (op) {
		case '+': a += v; break;
		case '-': a -= v; break;
		case '*': a *= v; break;
		case '/': a /= v; break;
	}

	cout << "Result:\n" << a;
	cout << "Operation (+/-): ";
	cin >> op;

	switch (op) {
		case '+': a++; break;
		case '-': --a; break;
	}

	cout << "Result:\n" << a;
	system("pause");
	return EXIT_SUCCESS;
}