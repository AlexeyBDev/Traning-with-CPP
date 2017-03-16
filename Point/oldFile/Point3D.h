// 140317
// Point3D - учебный класс точки, напсанный при обучении на курсах Специалист

#ifndef SPC_POINT_H
#define SPC_POINT_H

class Point3D
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
	Point3D();
	// конструктор преобразования
	Point3D(float k);
	// явный конструктор
	Point3D(float x, float y, float z = 0.f);
	// конструктор копирования
	Point3D(const Point3D &p);
	~Point3D();

	void Print(const int precision);
	void Print(const Point3D::axis axis = Point3D::XYZ, const int precision = 2); 
	Point3D &operator =(const Point3D &other);
	Point3D &operator +(const Point3D &other);
	Point3D &operator -(const Point3D &other);
	//explicit 
	Point3D &operator *(const float &scalar);
	Point3D &operator /(const float &scalar); 

	friend float dist(const Point3D &t1, const Point3D &t2, Point3D::dim dim = Point3D::_2D);
};

inline float Point3D::GetX() {
	return x_;
}

inline float Point3D::GetY() {
	return y_;
}

inline float Point3D::GetZ() {
	return z_;
}

#endif

