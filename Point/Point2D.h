// 160317
// Point3D - ������� ����� �����, ��������� ��� �������� �� ������ ����������
//---------------------------------------------------------------------------

#ifndef POINT2D_H
#define POINT2D_H


class Point2D
{
private:
	float x_, y_;

public:
	// inline ������
	// ������� ��������������� ����������
	float GetX();
	float GetY();
	// ��������� ��������������� ����������
	void SetX(float x);
	void SetY(float y);

	// ����������� �� ���������
	Point2D();
	// ����������� ��������������
	Point2D(float k);
	// ����� �����������
	Point2D(float x, float y);
	// ����������� �����������
	Point2D(const Point2D &p);
	~Point2D();

	void Print(const int precision = 2);
	void Move(const float dx, const float dy);
	Point2D &operator =(const Point2D &other);
	Point2D &operator +(const Point2D &other);
	Point2D &operator -(const Point2D &other);
	//explicit 
	Point2D &operator *(const float &scalar);
	//Point2D &operator /(const float &scalar);

	friend float dist(const Point2D &t1, const Point2D &t2);

};

inline float Point2D::GetX()
{
	return x_;
}

inline float Point2D::GetY()
{
	return y_;
}


#endif
