// макрос для отладки
#if defined(_DEBUG)
#define POINT3D_DEBUG 0
#else
#define POINT3D_DEBUG 0
#endif

#include <iostream>
#include <iomanip>
//#include <cmath>

using std::cout;
using std::endl;

#include "Point3D.h"


void Point3D::SetZ(float z)
{
	z_ = z;
}


Point3D::Point3D() : Point2D(0.f, 0.f), z_(0.f)
{
#if POINT3D_DEBUG
	cout << "---Point3D::Point3D() : Point2D(0.f, 0.f), z_(0.f)" << " adr: " << this << endl;
#endif
}


Point3D::Point3D(float x, float y, float z) : Point2D(x, y), z_(z)
{
#if POINT3D_DEBUG
	cout << "---Point3D::Point3D(float x, float y, float z) : Point2D(x, y), z_(z)" << " adr: " << this << endl;
#endif
}

Point3D::Point3D(const Point2D& xy, float z) : Point2D(xy), z_(z)
{
#if POINT3D_DEBUG
	cout << "---Point3D::Point3D(float x, float y, float z) : Point2D(x, y), z_(z)" << " adr: " << this << endl;
#endif
}

Point3D::Point3D(const Point3D& xyz) : Point2D(xyz), z_(xyz.z_)
{
#if POINT3D_DEBUG
	cout << "---Point3D::Point3D(const Point3D& xyz) : Point2D(xyz), z_(xyz.z_)" << " adr: " << this << endl;
#endif
}

Point3D::~Point3D()
{
#if POINT3D_DEBUG
	cout << "---Point3D::~Point3D()" << " adr: " << this << endl;
#endif
}

void Point3D::Print(const int precision)
{
#if POINT3D_DEBUG
	cout << "---void Point3D::Print(const int precision)" << endl;
#endif
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::fixed | std::ios::showpoint);
	cout << "(" << Point2D::GetX() << ", " << Point2D::GetY() << ", " << z_ << ")";
}

void Point3D::Move(const float dx, const float dy, const float dz)
{
	Point2D::SetX(Point2D::GetX() + dx);
	Point2D::SetY(Point2D::GetY() + dy);
	z_ += dz;
}

Point3D& Point3D::operator=(const Point3D& other)
{
	// проверка на присвоение самому себе
	if (this == &other) return *this;
#if POINT3D_DEBUG
	cout << "---Point3D& Point3D::operator=(const Point3D& other)" << endl;
#endif
	Point2D::operator=(other);
	z_ = other.z_;
	return *this;
}

Point3D& Point3D::operator+(const Point3D& other)
{
#if POINT3D_DEBUG
	cout << "---Point3D& Point3D::operator+(const Point3D& other)" << endl;
#endif
	Point2D::operator+(other);
	z_ += other.z_;
	return *this;
}

Point3D& Point3D::operator-(const Point3D& other)
{
#if POINT3D_DEBUG
	cout << "---Point3D& Point3D::operator-(const Point3D& other)" << endl;
#endif
	Point2D::operator-(other);
	z_ -= other.z_;
	return *this;
}

Point3D& Point3D::operator*(const float& scalar)
{
#if POINT3D_DEBUG
	cout << "---Point3D& Point3D::operator*(const float& scalar)" << endl;
#endif
	Point2D::operator*(scalar);
	z_ *= scalar;
	return *this;
}
