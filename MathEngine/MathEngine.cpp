#include <iostream>
#include <string>
#include "src/Vector3/Vector3n.h"

int main(int argc, const char* argv[])
{
	V3::Vector3n vector(1, 2, 3);
	V3::Vector3n vector1(0, 0, 0);
	V3::Vector3n vector2(4, 5, 6);
	V3::Vector3n vector3(1, 1, 1);
	V3::Vector3n vector4(1, 3, 2);
	V3::Vector3n vector5(9, 10, 2);

	std::cout << "vector: " << vector.x << " " << vector.y << " " << vector.z << std::endl;
	std::cout << "vector1: " << vector1.x << " " << vector1.y << " " << vector1.z << std::endl;
	std::cout << "vector2: " << vector2.x << " " << vector2.y << " " << vector2.z << std::endl;
	std::cout << "vector3: " << vector3.x << " " << vector3.y << " " << vector3.z << std::endl;
	std::cout << "vector4: " << vector4.x << " " << vector4.y << " " << vector4.z << std::endl;
	std::cout << "vector5: " << vector5.x << " " << vector5.y << " " << vector5.z << std::endl;
	
	// test vector operands
	// sum and subtraction tests
	/*
	V3::Vector3n result = vector + vector2;

	std::cout << "Result of sum of vectors: " << result.x << " " << result.y << " " << result.z << std::endl;

	vector3 += vector4;
	std::cout << "vector3 after sum with vector4: " << vector3.x << " " << vector3.y << " " << vector3.z << std::endl;

	V3::Vector3n resultReset = result - vector2;
	std::cout << "Result of subtraction of vectors: " << resultReset.x << " " << resultReset.y << " " << resultReset.z << std::endl;

	vector3 -= vector4;
	std::cout << "vector3 after subtraction with vector4: " << vector3.x << " " << vector3.y << " " << vector3.z << std::endl;

	vector1 -= vector2;
	std::cout << "vector1 after subtraction with vector2: " << vector1.x << " " << vector1.y << " " << vector1.z << std::endl;*/

	// multiplication and division by scalar tests
	/*vector *= 2;
	std::cout << "vector multiplied by 2: " << vector.x << " " << vector.y << " " << vector.z << std::endl;

	V3::Vector3n multiplied = vector2 * 5;
	std::cout << "result of vector2 multiplied by 5: " << multiplied.x << " " << multiplied.y << " " << multiplied.z << std::endl;

	vector /= 3;
	std::cout << "vector divided by 3: " << vector.x << " " << vector.y << " " << vector.z << std::endl;

	V3::Vector3n divided = vector2 / 2;
	std::cout << "result of vector2 divided by 2: " << divided.x << " " << divided.y << " " << divided.z << std::endl;*/

	// vector product
	/*float dotProduct = vector.dot(vector2);
	std::cout << "Dot product of vector with vector2: " << dotProduct << std::endl;

	float dotProductMult = vector * vector4;
	std::cout << "Dot product of vector with vector4: " << dotProductMult << std::endl;*/

	// cross product
	/*V3::Vector3n crossProduct = vector.cross(vector2);
	std::cout << "Cross product of vector with vector2: " << crossProduct.x << " " << crossProduct.y << " " << crossProduct.z << std::endl;

	V3::Vector3n crossProductMod = vector3 % vector4;
	std::cout << "Cross product of vector3 with vector4: " << crossProductMod.x << " " << crossProductMod.y << " " << crossProductMod.z << std::endl;

	vector5 %= crossProductMod;
	std::cout << "Cross product of vector5 with crossProductMod: " << vector5.x << " " << vector5.y << " " << vector5.z << std::endl;*/

	// magnitude of a vector
	/*float magnitude = vector5.magnitude();
	std::cout << "magnitude of vector5: " << magnitude << std::endl;*/

	// convert to unit vector
	/*vector5.normalize();
	std::cout << "unit vector of vector5: " << vector5.x << " " << vector5.y << " " << vector5.z << std::endl;*/
}