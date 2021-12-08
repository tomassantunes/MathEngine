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
	};
}

