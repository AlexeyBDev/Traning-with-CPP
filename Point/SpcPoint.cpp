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

#include "SpcPoint.h"


void SpcPoint::SetX(float x)
{
	x_ = x;
}

void SpcPoint::SetY(float y)
{
	y_ = y;
}

void SpcPoint::SetZ(float z)
{
	z_ = z;
}

SpcPoint::SpcPoint() : x_(0.f), y_(0.f), z_(0.)
{
#if SPC_POINT_DEBUG
	cout << "SpcPoint::SpcPoint()" << endl;
#endif
}

SpcPoint::SpcPoint(float k) : x_(k), y_(k), z_(k)
{
#if SPC_POINT_DEBUG
	cout << "SpcPoint::SpcPoint(float k)" << endl;
#endif
}

SpcPoint::SpcPoint(float x, float y, float z) : x_(x), y_(y), z_(z)
{
#if SPC_POINT_DEBUG
	cout << "SpcPoint::SpcPoint(float x, float y, float z)" << endl;
#endif
}

SpcPoint::SpcPoint(const SpcPoint& p) : x_(p.x_), y_(p.y_), z_(p.z_)
{
#if SPC_POINT_DEBUG
	cout << "SpcPoint::SpcPoint(const SpcPoint& p)" << endl;
#endif
}

SpcPoint::~SpcPoint()
{
#if SPC_POINT_DEBUG
	cout << "SpcPoint::~SpcPoint()" << endl;
#endif
}

void SpcPoint::Print(const int precision)
{
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::showpoint | std::ios::fixed);
	cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

void SpcPoint::Print(const SpcPoint::axis axis, const int precision)
{
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::showpoint | std::ios::fixed);
	switch (axis)
	{
	case SpcPoint::X: cout << "(" << x_ << ")"; break;
	case SpcPoint::Y: cout << "(" << y_ << ")"; break;
	case SpcPoint::Z: cout << "(" << z_ << ")"; break;
	case SpcPoint::XY: cout << "(" << x_ << ", " << y_ << ")"; break;
	case SpcPoint::YZ: cout << "(" << y_ << ", " << z_ << ")"; break;
	case SpcPoint::XZ: cout << "(" << x_ << ", " << z_ << ")"; break;
	case SpcPoint::XYZ: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	default: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	}
}

SpcPoint& SpcPoint::operator =(const SpcPoint& other)
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
	cout << "SpcPoint& SpcPoint::operator=(const SpcPoint& other)" << endl;
#endif

	return *this;
}

SpcPoint & SpcPoint::operator+(const SpcPoint & other)
{
	// TODO: insert return statement here
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;

#if SPC_POINT_DEBUG
	cout << "SpcPoint & SpcPoint::operator+(const SpcPoint & other)" << endl;
#endif

	return *this;
}

SpcPoint & SpcPoint::operator-(const SpcPoint & other)
{
	// TODO: insert return statement here
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;

#if SPC_POINT_DEBUG
	cout << "SpcPoint & SpcPoint::operator-(const SpcPoint & other)" << endl;
#endif

	return *this;
}

SpcPoint & SpcPoint::operator*(const float & scalar)
{
	// TODO: insert return statement here
	x_ *= scalar;
	y_ *= scalar;
	z_ *= scalar;

#if SPC_POINT_DEBUG
	cout << "SpcPoint & SpcPoint::operator*(const float & scalar)" << endl;
#endif

	return *this;
}

SpcPoint & SpcPoint::operator/(const float & scalar)
{
	// TODO: insert return statement here
	if (scalar == 0.0f) return *this;
	x_ /= scalar;
	y_ /= scalar;
	z_ /= scalar;

#if SPC_POINT_DEBUG
	cout << "SpcPoint & SpcPoint::operator/(const float & scalar)" << endl;
#endif

	return *this;
}

float dist(const SpcPoint & t1, const SpcPoint & t2, SpcPoint::dim dim)
{
	float dx, dy, dz;
	dx = t1.x_ - t2.x_;
	dy = t1.y_ - t2.y_;
	dz = t1.z_ - t2.z_;
	switch (dim) 
	{
	case SpcPoint::_2D: return sqrt(dx * dx + dy * dy);
	case SpcPoint::_3D: return sqrt(dx * dx + dy * dy + dz * dz);
	default: return sqrt(dx * dx + dy * dy);
	}
	return 0.0f;
}
