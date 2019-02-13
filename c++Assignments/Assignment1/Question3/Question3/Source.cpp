#include<iostream>
using namespace std;
class Complex
{
	int real, img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int a)
	{
		real = a;
		img = a;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	void add(Complex &c1, Complex &c2)
	{
		real = c1.real + c2.real;
		img = c1.img + c2.img;
	}
	void mul(Complex &c1, Complex &c2)
	{
		real = (c1.real*c2.real)-(c1.img*c2.img);
		img = (c1.real*c2.img) + (c1.img*c2.real);
	}
	void display()
	{
		cout << real << "+" << img << "i"<<endl;
	}
};
int main()
{
	Complex c, c1(3), c2(1,2);
	c.add(c1, c2);
	c.display();
	c.mul(c1, c2);
	c.display();
}