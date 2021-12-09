#pragma once
#include "../Vector3/Vector3n.h"

namespace ME 
{
	class Quaternion 
	{
	public:
		float s;
		Vector3n v;
		
		Quaternion();
		Quaternion(float uS, Vector3n& uV);
		Quaternion(const Quaternion& value);

		~Quaternion();
		
		void show();
		
		Quaternion& operator = (const Quaternion& value);

		// adding quaternions
		void operator += (const Quaternion& q);
		Quaternion operator + (const Quaternion& q) const;

		// subtracting quaternions
		void operator -= (const Quaternion& q);
		Quaternion operator - (const Quaternion& q) const;

		// multiplicating quaternions
		void operator *= (const Quaternion& q);
		Quaternion operator * (const Quaternion& q) const;
		Quaternion multiply(const Quaternion& q) const;

		// multiplicating quaternions by scalars
		void operator *= (const float value);
		Quaternion operator * (const float value) const;

		// calculating the norm of quaternions
		float norm();

		// convert from degrees to rad
		float DegreesToRad(float a);

		// calculating the unit norm of quaternions
		void normalize();
		void convertToUnitNorm();

		// conjugation of quaternions
		Quaternion conjugate();

		// invert quaternions
		Quaternion inverse();

		// rotating a vector
		Vector3n rotateVector(float uAngle, Vector3n& v);
	};
}