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

