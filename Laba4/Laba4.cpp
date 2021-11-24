#include<iostream>
#include<cmath>
const double PI = 3.141592653589793;
#define _USE_MATH_DEFINES
using namespace::std;
struct Point { double x, y; };
struct CenterPoint { double x, y; };
class Shape {
public:
	Point* arc;
	CenterPoint cenPoint;
	char Id [2];
	virtual void info() = 0;
	virtual ~Shape() {}
	static Shape* createShape(char);
	virtual double getArea() = 0;
	virtual void Move(double x, double y) = 0;
	virtual void Rotate(int degree, double x, double y) = 0;
	virtual CenterPoint cal_Cen_gravity() = 0;
};
class Square : public Shape {
public:	
	double side = 0;
		void info()
		{
		cout << "Квадрат" <<endl;
		}
	Square() {
		cout << "Укажите уникальный id квадрата состоящий из двух символов" << endl;
		cin >> Id;
		arc = new Point[4];
		cout << "Укажите координаты (x, y) левой нижней грани" << endl;
		cin >> arc[0].x >> arc[0].y;
		cout << "Укажите длину сторон" << endl;
		cin >> side;
		arc[1].x = arc[0].x;
		arc[1].y = arc[0].y + side;
		arc[2].x = arc[0].x + side;
		arc[2].y = arc[1].y;
		arc[3].x = arc[2].x;
		arc[3].y = arc[0].y;
		cenPoint.x = arc[2].x / 2;
		cenPoint.y = arc[2].y / 2;
		
	}
	double getArea() 
	{ 
		return (side * side); 
	}
	CenterPoint cal_Cen_gravity()
	{	
		cenPoint.x = arc[2].x / 2;
		cenPoint.y = arc[2].y / 2;
		return cenPoint;
	}
	void Shape::Move(double x , double y)
	{
		arc[0].x += x;
		arc[0].y += y;
		arc[1].x += x;
		arc[1].y += y;
		arc[2].x += x;
		arc[2].y += y;
		arc[3].x += x;
		arc[3].y += y;
		cenPoint.x += x;
		cenPoint.y += y;
	}
	void Shape::Rotate (int degree, double x, double y )
	{
		float a = degree * PI / 180; //переводим в радианы 

		float X, Y; //повернутые коор-ты углов фигуры 



		X = (arc[0].x - x) * cos(a) - (arc[0].y - y) * sin(a);

		Y = (arc[0].x - x) * sin(a) + (arc[0].y - y) * cos(a);

		cout << "x1=" << X + x << endl;

		cout << "y1=" << Y + y << endl;



		X = (arc[1].x - x) * cos(a) - (arc[1].y - y) * sin(a);

		Y = (arc[1].x - x) * sin(a) + (arc[1].y - y) * cos(a);

		cout << "x2=" << X + x << endl;

		cout << "y2=" << Y + y << endl;



		X = (arc[2].x - x) * cos(a) - (arc[2].y - y) * sin(a);

		Y = (arc[2].x - x) * sin(a) + (arc[2].y - y) * cos(a);

		cout << "x3=" << X + x << endl;

		cout << "y3=" << Y + y << endl;



		X = (arc[3].x - x) * cos(a) - (arc[3].y - y) * sin(a);

		Y = (arc[3].x - x) * sin(a) + (arc[3].x - y) * cos(a);

		cout << "x4=" << X + x << endl;

		cout << "y4=" << Y + y << endl;
	}
	~Square() 
	{ 
		delete[] arc; 
	}
};
class Rectangle : public Shape
{	public:
	double side1 = 0;
	double side2 = 0;
	void info()
	{
		cout << "Прямоугольник" << endl;
	}
	Rectangle()
	{
		cout << "Укажите уникальный id прямоугольника состоящий из двух символов" << endl;
		cin >> Id;
		arc = new Point[4];
		cout << "Укажите координаты (x, y) левой нижней грани" << endl;
		cin >> arc[0].x >> arc[0].y;
		cout << "Укажите длину ширину" << endl;
		cin >> side1;
		cout << "Укажите длину" << endl;
		cin >> side2;
		arc[1].x = arc[0].x;
		arc[1].y = arc[0].y + side1;
		arc[2].x = arc[0].x + side2;
		arc[2].y = arc[1].y;
		arc[3].x = arc[2].x;
		arc[3].y = arc[0].y;
		cenPoint.x = arc[2].x / 2;
		cenPoint.y = arc[2].y / 2;
	}
	double getArea()
	{
		return side1 * side2;
	}
	CenterPoint cal_Cen_gravity()
	{
		cenPoint.x = arc[2].x / 2;
		cenPoint.y = arc[2].y / 2;
		return cenPoint;
	}
	void Shape::Move(double x, double y)
	{
		arc[0].x += x;
		arc[0].y += y;
		arc[1].x += x;
		arc[1].y += y;
		arc[2].x += x;
		arc[2].y += y;
		arc[3].x += x;
		arc[3].y += y;
		cenPoint.x += x;
		cenPoint.y += y;
	}
	void Shape::Rotate(int degree, double x, double y)
	{
		float a = degree * PI / 180; //переводим в радианы 

		float X, Y; //повернутые коор-ты углов фигуры 



		X = (arc[0].x - x) * cos(a) - (arc[0].y - y) * sin(a);

		Y = (arc[0].x - x) * sin(a) + (arc[0].y - y) * cos(a);

		cout << "x1=" << X + x << endl;

		cout << "y1=" << Y + y << endl;



		X = (arc[1].x - x) * cos(a) - (arc[1].y - y) * sin(a);

		Y = (arc[1].x - x) * sin(a) + (arc[1].y - y) * cos(a);

		cout << "x2=" << X + x << endl;

		cout << "y2=" << Y + y << endl;



		X = (arc[2].x - x) * cos(a) - (arc[2].y - y) * sin(a);

		Y = (arc[2].x - x) * sin(a) + (arc[2].y - y) * cos(a);

		cout << "x3=" << X + x << endl;

		cout << "y3=" << Y + y << endl;



		X = (arc[3].x - x) * cos(a) - (arc[3].y - y) * sin(a);

		Y = (arc[3].x - x) * sin(a) + (arc[3].x - y) * cos(a);

		cout << "x4=" << X + x << endl;

		cout << "y4=" << Y + y << endl;
	}
	~Rectangle()
	{
		delete[]arc;
	}
};
//Фабричный метод
Shape* Shape::createShape(char cd)
{
	Shape* sh = 0;
	switch (cd) {
	case 'S':
		sh = new Square(); break;
	case 'R':
		sh = new Rectangle(); break;
	
	default: break;
	}
	return sh;
}
class Operat
{	public:
	void Compare_Areas(Shape a,Shape b )
	{
		if (a.getArea() > b.getArea())
			cout << "Фигура с Id " << a.Id << "Больше по площади" << endl;
		if (a.getArea()< b.getArea())
			cout << "Фигура с Id " << b.Id << "Больше по площади" << endl;
		if (a.getArea() == b.getArea())
			cout << "Фигуры равны по площади" << endl;
	}
	void IsIntersect()
	{
	
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Shape* p1 = 0;
	char T;
	cout << "Тип? ";
	cin >> T;
	p1 = Shape::createShape(T);
	if (!p1) return 0;
	p1->info();
	p1->getArea();
	delete p1;
	return 0;
}