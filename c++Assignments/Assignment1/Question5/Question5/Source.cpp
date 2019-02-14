#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	int mts,cms;
public:
	Distance1()
	{
		mts = 0;
		cms = 0;
	}
	void set_val(int m, int c)
	{
		mts = m;
		cms = c;
	}
	friend void add(Distance1, Distance2);
};
class Distance2
{
	int ft;
	int in;
public:
	Distance2()
	{
		ft = 0;
		in = 0;
	}
	void set_val(int x, int y)
	{
		ft = x;
		in = y;
	}
	friend void add(Distance1, Distance2);
};
void add(Distance1 d1, Distance2 d2)
{
	float dist;
	dist = d1.mts + (d1.cms*0.01) + (d2.ft * 0.3048) + (d2.in*0.0254);
	cout << dist << endl;
}
int main()
{
	Distance1 d1;
	Distance2 d2;
	int a, b, c, d;
	cout << "enter meters and centimeters : " << endl;
	cin >> a >> b;
	d1.set_val(a, b);
	cout << "enter feets and inches : " << endl;
	cin >> c >> d;
	d2.set_val(c, d);
	add(d1, d2);
}