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

void SpcPoint::Print(const int axis,const int precision)
{
	cout << std::setprecision(precision)
		<< std::setiosflags(std::ios::showpoint | std::ios::fixed);
	switch (axis)
	{
	case X: cout << "(" << x_ << ")"; break;
	case Y: cout << "(" << y_ << ")"; break;
	case Z: cout << "(" << z_ << ")"; break;
	case XY: cout << "(" << x_ << ", " << y_ << ")"; break;
	case YZ: cout << "(" << y_ << ", " << z_ << ")"; break;
	case XZ: cout << "(" << x_ << ", " << z_ << ")"; break;
	case XYZ: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	default: cout << "(" << x_ << ", " << y_ << ", " << z_ << ")"; break;
	}
}

SpcPoint& SpcPoint::operator =(const SpcPoint& other)
{
	x_ = other.x_;
	y_ = other.y_;
	z_ = other.z_;

#if SPC_POINT_DEBUG
	cout << "SpcPoint& SpcPoint::operator=(const SpcPoint& other)" << endl;
#endif

	return *this;
}


