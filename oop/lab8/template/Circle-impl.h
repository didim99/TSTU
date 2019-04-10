#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#pragma once

using namespace std;

template<typename T>
inline Circle<T>::Circle()
{
	cx = cy = radius = 0;
}

template <typename T>
Circle<T>::Circle(T cx, T cy, T radius)
{
	this->cx = cx;
	this->cy = cy;
	this->radius = radius;
}

template <typename T>
inline void Circle<T>::print()
{
	cout << "This is a circle\n";
	cout << "x = " << cx << " y = " << cy;
	cout << " r = " << radius << "\n";
}

template <typename T>
T Circle<T>::perimeter()
{
	return 2 * M_PI * radius;
}

template <typename T>
T Circle<T>::area()
{
	return  M_PI * radius * radius;
}

template <typename T>
ostream& operator<< <>(ostream& out, Circle<T>& c) {
	out << "This is a circle\n";
	out << "x = " << c.cx << " y = " << c.cy;
	out << " r = " << c.radius << "\n";
	return out;
}

template <typename T>
istream& operator>> <>(istream& in, Circle<T>& c) {
	in >> c.cx >> c.cy >> c.radius;
	return in;
}

template<typename T>
inline bool Circle<T>::operator==(const Circle& c) const
{
	return radius == c.radius;
}

template<typename T>
inline bool Circle<T>::operator>(const Circle& c) const
{
	return radius > c.radius;
}

template<typename T>
inline bool Circle<T>::operator<(const Circle& c) const
{
	return radius < c.radius;
}

template <typename T>
inline Circle<T>& Circle<T>::operator++(void)
{
	this->radius++;
	return *this;
}

template <typename T>
inline Circle<T>& Circle<T>::operator--(void)
{
	this->radius--;
	return *this;
}

template <typename T>
inline Circle<T> Circle<T>::operator++(int)
{
	Circle c(cx, cy, radius);
	this->radius++;
	return c;
}

template <typename T>
inline Circle<T> Circle<T>::operator--(int)
{
	Circle c(cx, cy, radius);
	this->radius--;
	return c;
}