#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D :
	public Point2D
{
private:
	float z_;
public:
	// inline методы
	// возврат соответствующей координаты
	float GetZ();
	// установка соответствующей координаты
	void SetZ(float z);

	Point3D();
	Point3D(float x, float y, float z);
	Point3D(const Point2D &xy, float z);
	Point3D(const Point3D &xyz);
	~Point3D();

	void Print(const int precision = 2);
	void Move(const float dx, const float dy, const float dz);
	Point3D &operator =(const Point3D &other);
	Point3D &operator +(const Point3D &other);
	Point3D &operator -(const Point3D &other);
	Point3D &operator *(const float &scalar);
};


inline float Point3D::GetZ()
{
	return z_;
}


#endif

