// 140317
// SpcPoint - ������� ����� �����, ��������� ��� �������� �� ������ ����������

#ifndef SPC_POINT_H
#define SPC_POINT_H

class SpcPoint
{
private:
	float x_, y_, z_;

public:
	// ������������� �������
	enum axis { X, Y, Z, XY, YZ, XZ, XYZ };
	// ������������� ���������
	enum dim {_2D = 2, _3D};
	// inline ������
	// ������� ��������������� ����������
	float GetX();
	float GetY();
	float GetZ();
	// ��������� ��������������� ����������
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	// ����������� �� ���������
	SpcPoint();
	// ����������� ��������������
	SpcPoint(float k);
	// ����� �����������
	SpcPoint(float x, float y, float z = 0.f);
	// ����������� �����������
	SpcPoint(const SpcPoint &p);
	~SpcPoint();

	void Print(const int precision);
	void Print(const SpcPoint::axis axis = SpcPoint::XYZ, const int precision = 2); 
	SpcPoint &operator =(const SpcPoint &other);
	SpcPoint &operator +(const SpcPoint &other);
	SpcPoint &operator -(const SpcPoint &other);
	//explicit 
	SpcPoint &operator *(const float &scalar);
	SpcPoint &operator /(const float &scalar); 

	friend float dist(const SpcPoint &t1, const SpcPoint &t2, SpcPoint::dim dim = SpcPoint::_2D);
};

inline float SpcPoint::GetX() {
	return x_;
}

inline float SpcPoint::GetY() {
	return y_;
}

inline float SpcPoint::GetZ() {
	return z_;
}

#endif

