#pragma once
constexpr size_t defaultSize = 2;
class Matrix
{
private:
	int** matrix;
	size_t rows = 0;
	size_t cols = 0;

	mutable bool isModified = 0;

	void setRows(size_t rows);
	void setCols(size_t cols);
	void setMatrix();

	void copyFrom(const Matrix& other);
	void free();
	bool isValidIndex(unsigned index) const;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	//Matrix& operator*=(const Matrix& rhs);
	Matrix& operator*=(int scalar);
	int* operator[](unsigned index);
	const int* operator[](unsigned index) const;
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
//Matrix& operator*(const Matrix& lhs, const Matrix& rhs){}
Matrix operator*(const Matrix& lhs, int scalar);

