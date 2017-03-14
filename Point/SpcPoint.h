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

	void Print(const int axis = XYZ,const int precision = 2);
	SpcPoint &operator =(const SpcPoint &other);
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

