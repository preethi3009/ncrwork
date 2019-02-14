#include<iostream>
#include<math.h>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	Point(int a)
	{
		x = a;
		y = 0;
	}
	friend float distance(Point, Point);
	 };
float distance(Point p1, Point p2)
{
	int x, y;
	x = pow((p1.x - p2.x),2);
	y = pow((p1.y - p2.y), 2);
	return sqrt(x+y);
}
int main()
{
	Point p1(3), p2(4, 1);
	float res;
	res = distance(p1, p2);
	cout << "distance calculated is -> " << res;
}