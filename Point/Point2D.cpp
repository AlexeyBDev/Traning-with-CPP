// макрос для отладки
#if defined(_DEBUG)
#define POINT2D_DEBUG 0
#else
#define POINT2D_DEBUG 0
#endif

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;

#include "Point2D.h"

void Point2D::SetX(float x)
{
	x_ = x;
}

void Point2D::SetY(float y)
{
	y_ = y;
}

Point2D::Point2D() : x_(0.f), y_(0.f)
{
#if POINT2D_DEBUG
	cout << "---Point2D::Point2D()" << " adr: " << this << endl;
#endif
}

Point2D::Point2D(float k) : x_(k), y_(k)
{
#if POINT2D_DEBUG
	cout << "---Point2D::Point2D(float k)" << " adr: " << this << endl;
#endif
}

Point2D::Point2D(float x, float y) : x_(x), y_(y)
{
#if POINT2D_DEBUG
	cout << "---Point2D::Point2D(float x, float y)" << " adr: " << this << endl;
#endif
}

Point2D::Point2D(const Point2D& p) : x_(p.x_), y_(p.y_)
{
#if POINT2D_DEBUG
	cout << "---Point2D::Point2D(const Point2D& p)" << " adr: " << this << endl;
#endif
}

Point2D::~Point2D()
{
#if POINT2D_DEBUG
	cout << "---Point2D::~Point2D()" << " adr: " << this << endl;
#endif
}

void Point2D::Print(const int precision)
{
#if POINT2D_DEBUG
	cout << "---void Point2D::Print(const int precision)" << endl;
#endif
	cout << std::setprecision(precision) 
	<< std::setiosflags(std::ios::fixed | std::ios::showpoint);
	cout << "(" << x_ << ", " << y_ << ")";
}

void Point2D::Move(const float dx, const float dy)
{
#if POINT2D_DEBUG
	cout << "---void Point2D::Move(const float dx, const float dy)" << endl;
#endif
	x_ += dx;
	y_ += dy;
}

Point2D& Point2D::operator=(const Point2D& other)
{
	// проверка на присвоение самому себе
	if (this == &other) return *this; 
#if POINT2D_DEBUG
	cout << "---Point2D& Point2D::operator=(const Point2D& other)" << endl;
#endif
	x_ = other.x_;
	y_ = other.y_;
	return *this;
}

Point2D& Point2D::operator+(const Point2D& other)
{
#if POINT2D_DEBUG
	cout << "---Point2D& Point2D::operator+(const Point2D& other)" << endl;
#endif
	x_ += other.x_;
	y_ += other.y_;
	return *this;
}

Point2D& Point2D::operator-(const Point2D& other)
{
#if POINT2D_DEBUG
	cout << "---Point2D& Point2D::operator-(const Point2D& other)" << endl;
#endif
	x_ -= other.x_;
	y_ -= other.y_;
	return *this;
}

Point2D& Point2D::operator*(const float& scalar)
{
#if POINT2D_DEBUG
	cout << "---Point2D& Point2D::operator*(const float& scalar)" << endl;
#endif
	x_ *= scalar;
	y_ *= scalar;
	return *this;
}

//Point2D& Point2D::operator/(const float& scalar)
//{
//#if POINT2D_DEBUG
//	cout << "Point2D& Point2D::operator/(const float& scalar)" << endl;
//#endif
//	if (scalar == 0.f) {
//		perror("division by zero"); 
//		exit(1);
//}
//	x_ *= scalar;
//	y_ *= scalar;
//	return *this;
//}

float dist(const Point2D& t1, const Point2D& t2)
{
#if POINT2D_DEBUG
	cout << "---float dist(const Point2D& t1, const Point2D& t2)" << endl;
#endif
	float dx, dy;
	dx = t1.x_ - t2.x_;
	dy = t1.y_ - t2.y_;
	return sqrt(dx * dx + dy * dy);
}
