#include "Vector3n.h"
#include <math.h>

namespace ME 
{
	Vector3n::Vector3n() :x(0.0), y(0.0), z(0.0) {}; // defines the vector coords as 0 bc no arguments given

	Vector3n::Vector3n(float X, float Y, float Z) :x(X), y(Y), z(Z) {};

	Vector3n::~Vector3n() {}

	Vector3n::Vector3n(const Vector3n& v) :x(v.x), y(v.y), z(v.z) {};

	// Defining vector
	Vector3n& Vector3n::operator = (const Vector3n& v) 
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	// adds v to this.vector
	void Vector3n::operator += (const Vector3n& v) // sum of two vectors stored in a third vector
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}
	
	// returns the vector of this.vector + v
	Vector3n Vector3n::operator + (const Vector3n& v) const
	{
		return Vector3n(x + v.x, y + v.y, z + v.z);
	}

	// subtracts v to this.vector
	void Vector3n::operator -= (const Vector3n& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	// returns the vector of this.vector - v
	Vector3n Vector3n::operator - (const Vector3n& v) const
	{
		return Vector3n(x - v.x, y - v.y, z - v.z);
	}

	// multiplies this.vector by scalar
	void Vector3n::operator *= (const float s) 
	{
		x *= s; 
		y *= s; 
		z *= s; 
	}

	// returns this.vector multiplied by scalar
	Vector3n Vector3n::operator * (const float s) const {
		return Vector3n(s * x, s * y, s * z);
	}

	// divides this.vector by scalar
	void Vector3n::operator /= (const float s)
	{
		x /= s;
		y /= s;
		z /= s;
	}

	// returns this.vector divided by scalar
	Vector3n Vector3n::operator / (const float s) const
	{
		return Vector3n(x / s , y / s, z / s);
	}

	// returns the dot product of this.vector and v
	float Vector3n::operator * (const Vector3n& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Vector3n::dot(const Vector3n& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	// returns the vector obtained by the cross product of this.vector and v
	Vector3n Vector3n::cross(const Vector3n& v)const 
	{
		return Vector3n(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		);
	}

	Vector3n Vector3n::operator % (Vector3n& v) const
	{
		return Vector3n(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		);
	}

	// cross product of this.vector and v
	void Vector3n::operator %= (Vector3n& v) 
	{
		*this = cross(v);
	}

	// returns the magnitude of this.vector
	float Vector3n::magnitude()
	{
		float magnitude = sqrt((x * x) + (y * y) + (z * z));
		return magnitude;
	}

	// converts this.vector to a unit vector
	void Vector3n::normalize() 
	{
		float mag = this->magnitude();

		if ( mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;

			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}
}