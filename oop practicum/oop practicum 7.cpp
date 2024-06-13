#include <iostream>
#include "Header.h"



void Matrix::setRows(size_t rows)
{
	this->rows = rows;
}

void Matrix::setCols(size_t cols)
{
	this->cols = cols;
}

void Matrix::setMatrix()
{
	matrix = new int* [rows];

	for (int i = 0;i < rows;i++)
	{
		matrix[i] = new int[cols];
	}


	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int rows, int cols)
{
	setRows(rows);
	setCols(cols);
	setMatrix();
}

Matrix::Matrix() : Matrix(defaultSize,defaultSize) {}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;

}

Matrix::~Matrix() {
	free();
}

void Matrix::copyFrom(const Matrix& other)
{
	setRows(other.rows);
	setCols(other.cols);
	setMatrix();
	
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}

	if (other.isModified)
		isModified = 1;
}
void Matrix::free()
{
	for (int i = 0;i < rows;i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	matrix = nullptr;
	rows = 0;
	cols = 0;
	isModified = 0;
}

bool Matrix::isValidIndex(unsigned index) const
{
	return index >= 0 && index < rows;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if (rows == rhs.rows && cols == rhs.cols)
	{
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				matrix[i][j] += rhs.matrix[i][j];
			}
		}
	}

	isModified = 1;
	return *this;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix toReturn(lhs);
	toReturn += rhs;

	return toReturn;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
	if (rows == rhs.rows && cols == rhs.cols)
	{
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				matrix[i][j] = rhs.matrix[i][j];
			}
		}
	}
	isModified = 1;
	return *this;
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix toReturn(lhs);
	toReturn -= rhs;
	return toReturn;
}

//unfinished
//Matrix& Matrix::operator*=(const Matrix& rhs)
//{
//	if (cols == rhs.rows)
//	{
//		for (int i = 0;i < rows;i++)
//		{
//			for (int j = 0;j < cols;j++)
//			{
//				matrix[i][j] *= rhs.matrix[j][i];
//			}
//		}
//	}
//	return *this;
//}

Matrix& Matrix::operator*=(int scalar)
{
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				matrix[i][j] *= scalar;
			}
		}

		isModified = 1;
		return *this;
}
Matrix operator*(const Matrix& lhs, int scalar)
{
	Matrix toReturn(lhs);
	toReturn *=scalar;
	return toReturn;
}

int* Matrix::operator[](unsigned index)
{
	if (!isValidIndex(index))
		return nullptr;
	return matrix[index];

}
const int* Matrix::operator[](unsigned index) const
{
	if (!isValidIndex(index))
		return nullptr;
		return matrix[index];
}


//bool, *=za matrici

int main() {
	Matrix myMatrix;
	myMatrix.operator*=(4);

	Matrix matrix2;
	Matrix result = myMatrix + matrix2;
}