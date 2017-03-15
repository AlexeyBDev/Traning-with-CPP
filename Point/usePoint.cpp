//Listing 2.3. ���� usePoint.cpp: ���������� ���, ������������ Point 

#include <iostream> 
#include <locale>
#include <cmath> 

#include "SpcPoint.h" 

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

//#define _DEBUG

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	{
	SpcPoint a;
	// ��� ������, ����� �������
	//cout << a.x_ << a.y_ << a.z_ << endl;
	// ������������� ����� ������ ������
	a.SetX(12.5f);
	a.SetY(-3.45f);
	a.SetZ(32.11f);

		cout << a.GetX() << ", "
			<< a.GetY() << ", "
			<< a.GetZ() << endl;

		SpcPoint b;
		cout << b.GetX() << ", "
			<< b.GetY() << ", "
			<< b.GetZ() << endl;
	}
	SpcPoint c(10.0f);
	cout << c.GetX() << ", "
		<< c.GetY() << ", "
		<< c.GetZ() << endl;

	SpcPoint d(5.34f, 4.f);
	cout << d.GetX() << ", "
		<< d.GetY() << ", "
		<< d.GetZ() << endl;

	SpcPoint e(d);
	cout << d.GetX() << ", "
		<< d.GetY() << ", "
		<< d.GetZ() << endl;

	d.Print();
	cout << endl;
	d.Print(SpcPoint::XYZ, 4);
	cout << endl;

	SpcPoint f;
	f = e;
	f.Print();
	SpcPoint g;
	g = f + d;
	g.Print();
	cout << endl;
	g = f - d;
	g.Print();
	cout << endl;

	f = f;
	f = f * 3.4f;
	f.Print();
	f = f / 12.434f;
	for (int i = 0; i < 10; ++i)
	{
		f.Print(i);
		cout << endl;
	}
	SpcPoint h;
	h = f / 0;
	h.Print(); cout << endl;
	f.SetZ(10);
	cout << "f = "; f.Print(); cout << endl;
	cout << "g = "; g.Print(); cout << endl;
	cout << "dist _2D = " << dist(f, g) << endl;
	cout << "dist _2D = " << dist(f, g, SpcPoint::_2D) << endl;
	cout << "dist _3D = " << dist(f, g, SpcPoint::_3D) << endl;

	return 0;
}

//���������� ������� ��� ��������� ���������� ����� ������� 


//double gdist(Point &a, Point &b)                   //�������� �� ������ 
//{                      //���������� Get...() ��� ������� � x_ � y_ 
//      return sqrt(pow(static_cast<double>(a.GetX()-b.GetX()),2) 
//                   +pow(static_cast<double>(a.GetY()-b.GetY()),2)); 
//} 
//
//int main() 
//{ 
//
////** 1 **������������� ������������ ���������� 
//
//      Point a;                    //�������� ���������� ������ Point � ����� 
//
////    a.x_ = 6;                   //ERROR, �.�. x_ �������� private 
////    a.y_ = 8;                   //ERROR, �.�. y_ �������� private 
//
//      a.SetX(6); 
//      a.SetY(8); 
//      cout << a.GetX() << ',' << a.GetY() << endl; 
//
//      Point *p = new Point;  //�������� ���������� ������ Point � ���� 
//      p->SetX(9); 
//      p->SetY(12); 
//      cout << p->GetX() << ',' << p->GetY() << endl; 
//
//      cout << "Distance = " 
//           << gdist(a,*p)         //������������, �.�. ��������� Point 
//           << endl; 
//
//      delete p;
//      	system("pause");
//                         //�������� �� ���� (������ ��������!) 
//} 

