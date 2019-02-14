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
	friend Complex add(Complex, Complex);
	friend Complex mul(Complex,Complex);
	void display()
	{
		cout << real << "+" << img << "i"<<endl;
	}
};
Complex add(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
Complex mul(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = (c1.real*c2.real) - (c1.img*c2.img);
	temp.img = (c1.real*c2.img) + (c1.img*c2.real);
	return temp;
}
int main()
{
	Complex c, c1(3), c2(1,2);
	c=add(c1, c2);
	c.display();
	c=mul(c1, c2);
	c.display();
}