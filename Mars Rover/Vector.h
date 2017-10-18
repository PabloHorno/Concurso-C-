#pragma once
#include <math.h>
#define PI 3.14159265359
template <typename T>
class Vector3D
{
public:
	Vector3D() { X = 0.0; Y = 0.0; Z = 0.0; };
	Vector3D(T x, T y, T z) { X = x; Y = y; Z = z; };
	Vector3D<T> operator+(Vector3D<T>a);
	Vector3D<T> rotacion(double angulo);
	T X;
	T Y;
	T Z;
};

template<typename T>
Vector3D<T> Vector3D<T>::operator+(Vector3D<T> a)
{
	return Vector3D<T>(a.X + this->X, a.Y + this->Y, a.Z + this->Z);
}
template<typename T>
Vector3D<T> Vector3D<T>::rotacion(double angulo)
{
	angulo *= PI / 180;
	return Vector3D<T>(cos(angulo)*X + sin(angulo)*Y, -sin(angulo)*X + cos(angulo)*Y,Z);
}

template <typename T>
class Vector2D
{
public:
	Vector2D() { X = 0.0; Y = 0.0; };
	Vector2D(T x, T y) { X = x; Y = y; };
	Vector2D<T> operator+(Vector2D<T>a);
	Vector2D<T> rotacion(double angulo);
public:
	T X;
	T Y;
};


template<typename T>
Vector2D<T> Vector2D<T>::operator+(Vector2D<T> a)
{
	return Vector2D<T>(a.X + this->X, a.Y + this.Y);
}

template<typename T>
Vector2D<T> Vector2D<T>::rotacion(double angulo)
{
	angulo *= PI / 180;
	return Vector2D<T>(cos(angulo)*X + sin(angulo)*Y, -sin(angulo)*X + cos(angulo)*Y);
}


