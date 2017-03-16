//Listing 2.3. Файл usePoint.cpp: клиентский код, использующий Point 

// макрос для отладки
#if defined(_DEBUG)
#define USEPOINT_DEBUG 0
#else
#define POINT3D_DEBUG 0
#endif

#include <iostream> 
#include <iomanip>
#include <locale>
#include <time.h> 

#include "Point2D.h" 
#include "Point3D.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

//#define _DEBUG

int main(int argc, char* argv[])
{
	// метка начала измерения времени
	clock_t before;
	double elapsed;
	before = clock();

	setlocale(LC_CTYPE, "rus");

	{
		// так нельзя, члены закрыты
		//cout << a.x_ << a.y_  << endl;

		
#if USEPOINT_DEBUG
		cout << "+++++Инициализация через методы класса+++++" << endl;
#endif
		Point2D a;
		a.SetX(12.5f);
		a.SetY(-3.45f);
#if USEPOINT_DEBUG
  		cout << "Точка 'a' инициализированна через методы Set: "
			<< a.GetX() << ", " << a.GetY() << endl;

		Point2D b;
		cout << "Точка 'b' (применение конструктора по умолчанию): "
			<< b.GetX() << ", " << b.GetY() << endl;
#endif

	}

	Point2D c(10.0f);
#if USEPOINT_DEBUG
  	cout << "Точка 'c' инициализация конструктором Point2D(float k): "
		<< c.GetX() << ", " << c.GetY() << endl;
#endif


	Point2D d(5.34f, 4.f);
#if USEPOINT_DEBUG
  	cout << "Точка 'd' инициализация конструктором Point2D(float x, float y): "
	<< d.GetX() << ", " << d.GetY() << endl;
#endif


	Point2D e(d);
#if USEPOINT_DEBUG
  	cout << "Точка 'e' инициализированна конструктором копирования: "
	<< d.GetX() << ", " << d.GetY() <<  endl;

	cout << endl << "+++++Применение методов класса+++++" << endl;

	cout << "Использование метода Print(): " << endl;
#endif

	d.Print();
	cout << endl;

#if USEPOINT_DEBUG
  	cout << "Print с модификатором точности Print(n): " << endl;
	for (int i = 0; i < 7; ++i) {
		d.Print(i); cout << endl;
	}
#endif


#if USEPOINT_DEBUG
  	cout << "Использование метода Move(float, float): " << endl;
#endif

	d.Move(23.354f, -2.4e2f);

#if USEPOINT_DEBUG
  	d.Print(4);
	cout << endl;
#endif


#if USEPOINT_DEBUG
  	cout << endl << "+++++Применение перегруженных операторов+++++" << endl;
#endif

	Point2D f;
	f = e;
#if USEPOINT_DEBUG
  	cout << "f = e: " << endl;
	f.Print();
	cout << endl;
#endif

	Point2D g;
	g = f + d;
#if USEPOINT_DEBUG
  	cout << "g = f + d: " << endl;
	g.Print();
	cout << endl;
#endif


	g = f - d;
#if USEPOINT_DEBUG
  	cout << "g = f - d: " << endl;
	g.Print();
	cout << endl;
#endif


	f = f;

	f = f * 3.4f;
#if USEPOINT_DEBUG
  	cout << "f = f * 3.4: " << endl;
	f.Print();
	cout << endl;
#endif


#if USEPOINT_DEBUG
  	cout << endl << "+++++Применение дружественных методов+++++" << endl;

	cout << "f = "; f.Print(); cout << endl;
	cout << "g = "; g.Print(); cout << endl;
#endif

	cout << "dist = " << dist(f, g) << endl << endl;

	cout << "+++++Работа с объектом Point3D+++++" << endl << endl;

	cout << "+++++Инициализация через методы класса+++++" << endl;
	Point3D a3d;
	a3d.SetX(23.4f);
	a3d.SetY(-0.324f);
	a3d.SetZ(897.990f);
	cout << "Точка 'a3d' инициализированна через метод класса Set: " << endl;
	cout << "(" << a3d.GetX() << ", " << a3d.GetY() << ", " << a3d.GetZ() << ")" << endl;
	
	Point3D b3d;
	cout << "Точка 'b3d' конструктор по умолчанию: " << endl;
	cout << "(" << b3d.GetX() << ", " << b3d.GetY() << ", " << b3d.GetZ() << ")" << endl;

	Point3D c3d(a3d); 
	c3d.Print();
	cout << endl;
	c3d.Move(1.0, 1.0, 1.0);
	c3d.Print();
	cout << endl;
	b3d = a3d + a3d;
	b3d.Print();
	cout << endl;
	a3d = c3d - b3d;
	a3d.Print();
	cout << endl;
	a3d = a3d * 34.23f;
	a3d.Print(4);
	cout << endl;
	

	// вычисление времени работы кода
	elapsed = clock() - before;
	cout << endl << "Код работает " << std::setprecision(3)
		<< std::setiosflags(std::ios::fixed | std::ios::showpoint)
		<< elapsed / CLOCKS_PER_SEC << " секунд." << endl;

	return 0;
}

//клиентская функция для измерения расстояния между точками 


//double gdist(Point &a, Point &b)                   //передача по ссылке 
//{                      //использует Get...() для доступа к x_ и y_ 
//      return sqrt(pow(static_cast<double>(a.GetX()-b.GetX()),2) 
//                   +pow(static_cast<double>(a.GetY()-b.GetY()),2)); 
//} 
//
//int main() 
//{ 
//
////** 1 **использование минимального интерфейса 
//
//      Point a;                    //Создание экземпляра класса Point в стеке 
//
////    a.x_ = 6;                   //ERROR, т.к. x_ объявлен private 
////    a.y_ = 8;                   //ERROR, т.к. y_ объявлен private 
//
//      a.SetX(6); 
//      a.SetY(8); 
//      cout << a.GetX() << ',' << a.GetY() << endl; 
//
//      Point *p = new Point;  //Создание экземпляра класса Point в куче 
//      p->SetX(9); 
//      p->SetY(12); 
//      cout << p->GetX() << ',' << p->GetY() << endl; 
//
//      cout << "Distance = " 
//           << gdist(a,*p)         //разадресация, т.к. требуется Point 
//           << endl; 
//
//      delete p;
//      	system("pause");
//                         //Удаление из кучи (нельзя забывать!) 
//} 

