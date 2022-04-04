#include <iostream>
#include <iomanip>
#pragma once

using namespace std;

class Matrix
{
public:
	Matrix(size_t rows, size_t cols);
	Matrix(const Matrix& src);
	virtual ~Matrix();

	friend ostream& operator<<(ostream& out, Matrix& m);
	friend istream& operator>>(istream& in, Matrix& m);
	Matrix& operator+(const Matrix &m) const;
	Matrix& operator-(const Matrix &m) const;
	Matrix& operator*(const Matrix &m) const;
	Matrix& operator+=(const double f);
	Matrix& operator-=(const double f);
	Matrix& operator*=(const double f);
	Matrix& operator/=(const double f);
	Matrix& operator++(void);
	Matrix  operator++(int);
	Matrix& operator--(void);
	Matrix  operator--(int);
private:
	size_t rows, cols;
	double *data;

	inline double get(size_t r, size_t c) const;
	inline void set(size_t r, size_t c, double v);
	inline bool operationPossible(const Matrix m) const;
};

