#include "Matrix.h"
#include <iostream>

int MATRIX_MAX_SIZE = 9;

namespace ME 
{
	// idendity matrix
	Matrix::Matrix() 
	{
		for (int i = 0; i < MATRIX_MAX_SIZE; i++)
		{
			matrixData[i] = 0.0f;
		}

		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}

	Matrix::Matrix(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) 
	{
		matrixData[0] = m0;
		matrixData[3] = m3;
		matrixData[6] = m6;

		matrixData[1] = m1;
		matrixData[4] = m4;
		matrixData[7] = m7;

		matrixData[2] = m2;
		matrixData[5] = m5;
		matrixData[8] = m8;
	}

	Matrix::~Matrix() {}

	void Matrix::show() 
	{
		std::cout << "(" << matrixData[0] << " " << matrixData[3] << " " << matrixData[6] << ")" << std::endl;
		std::cout << "(" << matrixData[1] << " " << matrixData[4] << " " << matrixData[7] << ")" << std::endl;
		std::cout << "(" << matrixData[2] << " " << matrixData[5] << " " << matrixData[8] << ")" << std::endl;
		std::cout << std::endl;
	}

	Matrix& Matrix::operator = (const Matrix& value) 
	{
		for(int i = 0; i < MATRIX_MAX_SIZE; i++) 
		{
			matrixData[i] = value.matrixData[i];
		}

		return *this;
	}

	// add matrixes
	Matrix& Matrix::operator + (const Matrix &v) const
	{
		Matrix m;

		for(int i = 0; i < MATRIX_MAX_SIZE; i++) 
		{
			m.matrixData[i] = matrixData[i] + v.matrixData[i];
		}

		return m;
	}

	void Matrix::operator += (const Matrix &v)
	{
		for (int i = 0; i < MATRIX_MAX_SIZE; i++)
		{
			matrixData[i] += v.matrixData[i];
		}
	}

	// subtract matrixes
	Matrix& Matrix::operator - (const Matrix& v) const
	{
		Matrix m;

		for (int i = 0; i < MATRIX_MAX_SIZE; i++)
		{
			m.matrixData[i] = matrixData[i] - v.matrixData[i];
		}

		return m;
	}

	void Matrix::operator -= (const Matrix& v)
	{
		for (int i = 0; i < MATRIX_MAX_SIZE; i++)
		{
			matrixData[i] -= v.matrixData[i];
		}
	}

	// multiply by scalar
	Matrix& Matrix::operator * (const float s) const 
	{
		Matrix m;

		for(int i = 0; i < MATRIX_MAX_SIZE; i++) 
		{
			m.matrixData[i] = matrixData[i] * s;
		}

		return m;
	}

	void Matrix::operator *= (const float s)
	{
		for (int i = 0; i < MATRIX_MAX_SIZE; i++)
		{
			matrixData[i] *= s;
		}
	}

	// multiply matrixes
	Matrix Matrix::operator * (const Matrix& m) const 
	{
		return Matrix(matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2],
			matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5],
			matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8],

			matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2],
			matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5],
			matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8],

			matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2],
			matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5],
			matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8]);
	}

	void Matrix::operator *= (const Matrix& m)
	{
		float t1;
		float t2;
		float t3;

		t1 = matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2];
		t2 = matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5];
		t3 = matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8];

		matrixData[0] = t1;
		matrixData[3] = t2;
		matrixData[6] = t3;

		t1 = matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2];
		t2 = matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5];
		t3 = matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8];

		matrixData[1] = t1;
		matrixData[4] = t2;
		matrixData[7] = t3;


		t1 = matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2];
		t2 = matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5];
		t3 = matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8];

		matrixData[2] = t1;
		matrixData[5] = t2;
		matrixData[8] = t3;
	}

	// set matrix to identity
	void Matrix::setMatrixAsIdentity() 
	{
		for(int i = 0; i < MATRIX_MAX_SIZE; i++) 
		{
			matrixData[i] = 0.0f;
		}

		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}

	// invert matrix
	void Matrix::setMatrixAsInvertedMatrix(const Matrix& m)
	{
		// adjunta
		// a = 4 * 8 - 7 * 5      d = -(3 * 8 - 5 * 6)   g = 3 * 7 - 6 * 4
		// b = -(1 * 8 - 7 * 2)   e = 0 * 8 - 6 * 2      h = -(0 * 7 - 6 * 1)
		// c = 1 * 5 - 2 * 4      f = -(0 * 5 - 3 * 2)   i = 0 * 4 - 1 * 3
		
		//determinante
		// (0 * 4 * 8) + (1 * 5 * 6) + (2 * 3 * 7) - (6 * 4 * 2) - (7 * 5 * 0) - (8 * 3 * 1)

		//float det = (t1 * m.matrixData[8] - t2 * m.matrixData[5] - t3 * m.matrixData[8] + t4 * m.matrixData[5] + t5 * m.matrixData[7] - t6 * m.matrixData[4]);

		float t1 = m.matrixData[0] * m.matrixData[4] * m.matrixData[8];
		float t2 = m.matrixData[1] * m.matrixData[5] * m.matrixData[6];
		float t3 = m.matrixData[2] * m.matrixData[3] * m.matrixData[7];
		float t4 = m.matrixData[6] * m.matrixData[4] * m.matrixData[2];
		float t5 = m.matrixData[7] * m.matrixData[5] * m.matrixData[0];
		float t6 = m.matrixData[8] * m.matrixData[3] * m.matrixData[1];

		float det = t1 + t2 + t3 - t4 - t5 - t6;

		if (det == 0.0) 
		{
			std::cout << "The determinant is equal to 0, then there is no inverted matrix." << std::endl;
			return;
		}

		float invD = 1.0f / det;

		float a = (m.matrixData[4] * m.matrixData[8] - m.matrixData[7] * m.matrixData[5]) * invD;
		float b = -(m.matrixData[1] * m.matrixData[8] - m.matrixData[7] * m.matrixData[2]) * invD;
		float c = (m.matrixData[1] * m.matrixData[5] - m.matrixData[2] * m.matrixData[4]) * invD;

		float d = -(m.matrixData[3] * m.matrixData[8] - m.matrixData[5] * m.matrixData[6]) * invD;
		float e = (m.matrixData[0] * m.matrixData[8] - m.matrixData[6] * m.matrixData[2]) * invD;
		float f = -(m.matrixData[0] * m.matrixData[5] - m.matrixData[3] * m.matrixData[2]) * invD;

		float g = (m.matrixData[3] * m.matrixData[7] - m.matrixData[6] * m.matrixData[4]) * invD;
		float h = -(m.matrixData[0] * m.matrixData[7] - m.matrixData[6] * m.matrixData[1]) * invD;
		float i = (m.matrixData[0] * m.matrixData[4] - m.matrixData[1] * m.matrixData[3]) * invD;

		matrixData[0] = a;
		matrixData[1] = b;
		matrixData[2] = c;

		matrixData[3] = d;
		matrixData[4] = e;
		matrixData[5] = f;

		matrixData[6] = g;
		matrixData[7] = h;
		matrixData[8] = i;
	}

	Matrix Matrix::getInverseOfMatrix() const
	{
		Matrix result;
		result.setMatrixAsInvertedMatrix(*this);
		return result;
	}

	void Matrix::invertMatrix()
	{
		setMatrixAsInvertedMatrix(*this);
	}
}