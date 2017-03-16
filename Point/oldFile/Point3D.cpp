//#ifdef _DEBUG
//#endif //_DEBUG
#if defined(_DEBUG)
	#define SPC_POINT_DEBUG 1
#else
	#define SPC_POINT_DEBUG 0
#endif

#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>
#include <cmath>

#include "Point3D.h"


void Point3D::SetX(float x)
{
	x_ = x;
}

void Point3D::SetY(float y)
{
	y_ = y;
}

void Point3D::SetZ(float z)
{
	z_ = z;
}

Point3D::Point3D() : x_(0.f), y_(0.f), z_(0.)
{
#if SPC_POINT_DEBUG
	cout << "Point3D::Point3D()" << endl;
#endif
}

Point3D::Point3D(float k) : x_(k), y_(k), z_(k)
{
#if SPC_POINT_DEBUG
	cout << "Point3D::Point3D(float k)" << endl;
#endif
}

Point3D::Point3D(float x, float y, float z) : x_(x), y_(y), z_(z)
{
#if SPC_POINT_DEBUG
	cout << "Point3D::Point3D(float x, float y, float z)" << endl;
#endif
}

Point3D::Point3D(const Point3D& p) : x_(p.x_), y_(p.y_), z_(p.z_)
{
#if SPC_POINT_DEBUG
	cout << "Point3D::Point3D(const Point3D& p)" << endl;
#endif
}

Point3D::~Point3D()
{
#if SPC_POINT_DEBUG
	cout << "Point3D::~Point3D()" << endl;
#endif
}

void Point3D::Print(const int precision)
{
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::showpoint | std::ios::fixed);
	cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

void Point3D::Print(const Point3D::axis axis, const int precision)
{
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::showpoint | std::ios::fixed);
	switch (axis)
	{
	case Point3D::X: cout << "(" << x_ << ")"; break;
	case Point3D::Y: cout << "(" << y_ << ")"; break;
	case Point3D::Z: cout << "(" << z_ << ")"; break;
	case Point3D::XY: cout << "(" << x_ << ", " << y_ << ")"; break;
	case Point3D::YZ: cout << "(" << y_ << ", " << z_ << ")"; break;
	case Point3D::XZ: cout << "(" << x_ << ", " << z_ << ")"; break;
	case Point3D::XYZ: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	default: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	}
}

Point3D& Point3D::operator =(const Point3D& other)
{
	if (this == &other) {
#if SPC_POINT_DEBUG
		cout << this << " == " << &other << endl;
#endif
	return *this;
	}
	x_ = other.x_;
	y_ = other.y_;
	z_ = other.z_;

#if SPC_POINT_DEBUG
	cout << "Point3D& Point3D::operator=(const Point3D& other)" << endl;
#endif

	return *this;
}

Point3D & Point3D::operator+(const Point3D & other)
{
	// TODO: insert return statement here
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;

#if SPC_POINT_DEBUG
	cout << "Point3D & Point3D::operator+(const Point3D & other)" << endl;
#endif

	return *this;
}

Point3D & Point3D::operator-(const Point3D & other)
{
	// TODO: insert return statement here
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;

#if SPC_POINT_DEBUG
	cout << "Point3D & Point3D::operator-(const Point3D & other)" << endl;
#endif

	return *this;
}

Point3D & Point3D::operator*(const float & scalar)
{
	// TODO: insert return statement here
	x_ *= scalar;
	y_ *= scalar;
	z_ *= scalar;

#if SPC_POINT_DEBUG
	cout << "Point3D & Point3D::operator*(const float & scalar)" << endl;
#endif

	return *this;
}

Point3D & Point3D::operator/(const float & scalar)
{
	// TODO: insert return statement here
	if (scalar == 0.0f) return *this;
	x_ /= scalar;
	y_ /= scalar;
	z_ /= scalar;

#if SPC_POINT_DEBUG
	cout << "Point3D & Point3D::operator/(const float & scalar)" << endl;
#endif

	return *this;
}

float dist(const Point3D & t1, const Point3D & t2, Point3D::dim dim)
{
	float dx, dy, dz;
	dx = t1.x_ - t2.x_;
	dy = t1.y_ - t2.y_;
	dz = t1.z_ - t2.z_;
	switch (dim) 
	{
	case Point3D::_2D: return sqrt(dx * dx + dy * dy);
	case Point3D::_3D: return sqrt(dx * dx + dy * dy + dz * dz);
	default: return sqrt(dx * dx + dy * dy);
	}
	return 0.0f;
}
