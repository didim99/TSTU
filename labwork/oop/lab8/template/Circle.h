#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Circle
{
public:
	Circle();
	Circle(T cx, T cy, T radius);
	void print();
	T perimeter();
	T area();

	friend ostream& operator<< <>(ostream& out, Circle<T>& c);
	friend istream& operator>> <>(istream& in, Circle<T>& c);
	bool operator==(const Circle& c) const;
	bool operator>(const Circle& c) const;
	bool operator<(const Circle& c) const;
	Circle& operator++(void);
	Circle  operator++(int);
	Circle& operator--(void);
	Circle  operator--(int);
private:
	T cx, cy;
	T radius;
};

#include "Circle-impl.h"