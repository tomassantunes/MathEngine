#include "Quaternion.h"
#include "../Vector3/Vector3n.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

namespace ME 
{
	Quaternion::Quaternion() : s(0.0), v(Vector3n(0, 0, 0)) {}
	
	Quaternion::Quaternion(float uS, Vector3n& uV) : s(uS), v(uV) {}

	Quaternion::Quaternion(const Quaternion& value) 
	{
		s = value.s;
		v = value.v;
	}

	Quaternion::~Quaternion() {}

	Quaternion& Quaternion::operator = (const Quaternion& value)
	{
		s = value.s;
		v = value.v;

		return *this;
	}

	void Quaternion::show() 
	{
		std::cout << "Scalar: " << s << " Vector: ";
		v.show();
	}

	// adding quaternions
	void Quaternion::operator += (const Quaternion& q) 
	{
		s += q.s;
		v += q.v;
	}

	Quaternion Quaternion::operator + (const Quaternion& q) const
	{
		float scalar = s + q.s;
		Vector3n imaginary = v + q.v;

		return Quaternion(scalar, imaginary);
	}

	// subtracting quaternions
	void Quaternion::operator -= (const Quaternion& q) 
	{
		s -= q.s;
		v -= q.v;
	}

	Quaternion Quaternion::operator - (const Quaternion& q) const 
	{
		float scalar = s - q.s;
		Vector3n imaginary = v - q.v;

		return Quaternion(scalar, imaginary);
	}

	// multiplicating quaternions
	void Quaternion::operator *= (const Quaternion& q)
	{
		(*this) = multiply(q);
	}

	Quaternion Quaternion::operator * (const Quaternion& q) const 
	{
		float scalar = s * q.s - v.dot(q.v);

		Vector3n imaginary = q.v * s + v * q.s + v.cross(q.v);

		return Quaternion(scalar, imaginary);
	}

	Quaternion Quaternion::multiply(const Quaternion& q) const 
	{
		return (*this) * q;
	}
	
	// multiplicating quaternions by scalars
	void Quaternion::operator *= (const float value) 
	{
		s *= value;
		v *= value;
	}

	Quaternion Quaternion::operator * (const float value) const
	{
		float scalar = s * value;
		Vector3n imaginary = v * value;

		return Quaternion(scalar, imaginary);
	}
	
	// calculating the norm of quaternions
	float Quaternion::norm() 
	{
		float auxS = s * s;
		float auxV = v * v;

		return sqrt(auxS + auxV);
	}

	// convert from degres to rad
	float Quaternion::DegreesToRad(float a) 
	{
		return (a / 180) * M_PI;
	}

	// calculating the unit norm of quaternions
	void Quaternion::normalize() 
	{
		if (norm() != 0)
		{
			float normValue = 1 / norm();
			
			s *= normValue;
			v *= normValue;
		}
	}

	void Quaternion::convertToUnitNorm()
	{
		float angle = DegreesToRad(s);
		v.normalize();
		s = cosf(angle * 0.5);
		v *= sinf(angle * 0.5);
	}

	// conjugation of quaternions
	Quaternion Quaternion::conjugate()
	{
		Vector3n imaginary = v * (-1);

		return Quaternion(s, imaginary);
	}

	// invert quaternions
	Quaternion Quaternion::inverse()
	{
		float absValue = norm();
		absValue *= absValue;
		absValue = 1 / absValue;

		Quaternion conjugateValue = conjugate();

		float scalar = conjugateValue.s * absValue;
		Vector3n imaginary = conjugateValue.v * absValue;

		return Quaternion(scalar, imaginary);
	}

	// rotating a vector
	Vector3n Quaternion::rotateVector(float uAngle, Vector3n& uAxis)
	{
		Quaternion pure(0, (v));

		uAxis.normalize();

		Quaternion real(uAngle, uAxis);
		real.convertToUnitNorm();

		Quaternion realInverse = real.inverse();

		Quaternion rotatedVector = real * pure * realInverse;

		return rotatedVector.v;
	}
}