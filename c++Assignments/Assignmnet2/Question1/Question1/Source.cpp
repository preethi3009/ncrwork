#include<iostream>
using namespace std;
class Polar
{
	int angle;
	int radius;
public:
	static int count;
	Polar()
	{
		angle = 0;
		radius = 0;
		count++;
	}
	Polar(int x, int y)
	{
		angle = x;
		radius = y;
		count++;
	}
	Polar(Polar &c)
	{
		angle = c.angle;
		radius = c.radius;
		count++;
	}
	~Polar()
	{
		count--;
	}
	
};
int Polar::count;
int main()
{
	Polar p1, p2(2, 7);
	{
		Polar p4(7, 6);
		cout << "active objects inside the block " << endl;
		cout << Polar::count<<endl;
	}
	cout << "active objects outside the block " << endl;
	cout << Polar::count;
}