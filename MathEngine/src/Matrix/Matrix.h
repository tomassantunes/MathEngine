#pragma once

// 3x3 matrix - column major.X vector is 0, 1, 2, etc. (openGL prefer way)
//    0    3    6
//    1    4    7
//    2    5    8

namespace ME {
	class Matrix
	{
	public:
		float matrixData[9] = { 0.0 };

		Matrix();
		Matrix(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);

		~Matrix();

		void show();

		Matrix& operator = (const Matrix& value);
		
		// add matrixes
		Matrix& operator + (const Matrix &v) const;
		void operator += (const Matrix &v);

		// subtract matrixes
		Matrix& operator - (const Matrix& v) const;
		void operator -= (const Matrix& v);

		// multiply by scalar
		Matrix& operator * (const float s) const;
		void operator *= (const float s);

		// multiply matrixes
		Matrix operator * (const Matrix& v) const;
		void operator *= (const Matrix& v);

		// set matrix to identity
		void setMatrixAsIdentity();

		// invert matrix
		void setMatrixAsInvertedMatrix(const Matrix& m);
		Matrix getInverseOfMatrix(const Matrix& m) const;
		void invertMatrix();
	};
}
