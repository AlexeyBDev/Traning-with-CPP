// 160317
// Point3D - учебный класс точки, напсанный при обучении на курсах Специалист
//---------------------------------------------------------------------------

#ifndef POINT2D_H
#define POINT2D_H


class Point2D
{
private:
	float x_, y_;

public:
	// inline методы
	// возврат соответствующей координаты
	float GetX();
	float GetY();
	// установка соответствующей координаты
	void SetX(float x);
	void SetY(float y);

	// конструктор по умолчанию
	Point2D();
	// конструктор преобразования
	Point2D(float k);
	// явный конструктор
	Point2D(float x, float y);
	// конструктор копирования
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
