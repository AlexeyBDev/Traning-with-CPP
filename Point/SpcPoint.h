// 140317
// SpcPoint - учебный класс точки, напсанный при обучении на курсах Специалист

#ifndef SPC_POINT_H
#define SPC_POINT_H

class SpcPoint
{
private:
	float x_, y_, z_;

public:
	// квалификаторы доступа
	enum axis { X, Y, Z, XY, YZ, XZ, XYZ };
	// квалификаторы измерений
	enum dim {_2D = 2, _3D};
	// inline методы
	// возврат соответствующей координаты
	float GetX();
	float GetY();
	float GetZ();
	// установка соответствующей координаты
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	// конструктор по умолчанию
	SpcPoint();
	// конструктор преобразования
	SpcPoint(float k);
	// явный конструктор
	SpcPoint(float x, float y, float z = 0.f);
	// конструктор копирования
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

