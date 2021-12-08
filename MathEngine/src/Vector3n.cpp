#include "Vector3n.h"

namespace V3 
{
	Vector3n::Vector3n() :x(0.0), y(0.0), z(0.0) {}; // defines the vector coords as 0 bc no arguments given

	Vector3n::Vector3n(float X, float Y, float Z) :x(X), y(Y), z(Z) {};

	Vector3n::~Vector3n() {}

	Vector3n::Vector3n(const Vector3n& v) :x(v.x), y(v.y), z(v.z) {};

	Vector3n& Vector3n::operator = (const Vector3n& v) 
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}
}