#include "pch.h"
#include <memory.h>
#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t cols) {
	this->rows = rows;
	this->cols = cols;
	data = new double[rows * cols];
	memset(data, 0, rows * cols * sizeof(double));
}

Matrix::Matrix(const Matrix& src) {
	this->rows = src.rows;
	this->cols = src.cols;
	data = new double[rows * cols];
	memcpy(data, src.data, rows * cols * sizeof(double));
}

Matrix::~Matrix() {
	if (data) delete[] data;
}

ostream& operator<<(ostream& out, Matrix& m) {
	for (size_t r = 0; r < m.rows; r++) {
		for (size_t c = 0; c < m.cols; c++)
			out << setw(6) << setprecision(2) << m.get(r, c);
		cout << endl;
	}

	return out;
}

istream& operator>>(istream& in, Matrix& m) {
	double d;
	for (size_t r = 0; r < m.rows; r++) {
		for (size_t c = 0; c < m.cols; c++) {
			in >> d;
			m.set(r, c, d);
		}
	}

	return in;
}

Matrix& Matrix::operator+(const Matrix &m) const {
	if (!operationPossible(m)) throw
		invalid_argument("Impossible operation");
	Matrix *res = new Matrix(rows, cols);
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			res->set(r, c, get(r, c) + m.get(r, c));
		}
	}

	return *res;
}

Matrix& Matrix::operator-(const Matrix &m) const {
	if (!operationPossible(m)) throw
		invalid_argument("Impossible operation");
	Matrix *res = new Matrix(rows, cols);
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			res->set(r, c, get(r, c) - m.get(r, c));
		}
	}

	return *res;
}

Matrix& Matrix::operator*(const Matrix &m) const {
	if (cols != m.rows) throw
		invalid_argument("Impossible operation");
	Matrix *res = new Matrix(rows, m.cols);
	for (size_t x = 0; x < rows; x++) {
		for (size_t y = 0; y < m.cols; y++) {
			double t = 0;
			for (size_t k = 0; k < cols; k++)
				t += get(x, k) * m.get(k, y);
			res->set(x, y, t);
		}
	}

	return *res;
}

Matrix& Matrix::operator+=(const double v) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) + v);
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const double v) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) - v);
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const double v) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) * v);
		}
	}

	return *this;
}

Matrix& Matrix::operator/=(const double v) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) / v);
		}
	}

	return *this;
}

Matrix& Matrix::operator++(void) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) + 1);
		}
	}

	return *this;
}

Matrix& Matrix::operator--(void) {
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) - 1);
		}
	}

	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix *m = new Matrix(*this);
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) + 1);
		}
	}

	return *m;
}

Matrix Matrix::operator--(int) {
	Matrix *m = new Matrix(*this);
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			set(r, c, get(r, c) - 1);
		}
	}

	return *m;
}

inline double Matrix::get(size_t r, size_t c) const {
	return data[r * cols + c];
}

inline void Matrix::set(size_t r, size_t c, double v) {
	data[r * cols + c] = v;
}

inline bool Matrix::operationPossible(const Matrix m) const {
	return m.cols == cols && m.rows == rows;
}