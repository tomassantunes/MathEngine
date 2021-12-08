#pragma once
namespace V3 
{

	class Vector3n
	{
	public:
		float x;
		float y;
		float z;

		Vector3n();
		Vector3n(float X, float Y, float Z);

		~Vector3n();

		Vector3n(const Vector3n& v);
		Vector3n& operator = (const Vector3n& v);
		
		// Sum
		void operator += (const Vector3n& v);
		Vector3n operator + (const Vector3n& v)const;
		
		// Subtraction
		void operator -= (const Vector3n& v);
		Vector3n operator - (const Vector3n& v)const;

		// Multiplication by scalar
		void operator *= (const float s);
		Vector3n operator * (const float s)const;

		// Division by scalar
		void operator /= (const float s);
		Vector3n operator / (const float s)const;

		//vector product
		float operator * (const Vector3n& v)const;
		float dot(const Vector3n& v)const;

		// cross product
		Vector3n cross(const Vector3n& v)const;
		Vector3n operator % (Vector3n& v)const;
		void operator %= (Vector3n& v);

		float magnitude();

		void normalize();
	};
}

