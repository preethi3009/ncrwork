#include<iostream>
using namespace std;
class Complex {
	int real, img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int x, int y)
	{
		real = x;
		img = y;
	}
	Complex(const Complex &c)
	{
		real = c.real;
		img = c.img;
	}
	void display() {
		cout << "real: " << real;
		cout << " img: " << img<<endl;
	}
	Complex operator+(Complex &c)
	{
		Complex temp;
		temp.real=real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	Complex operator-(Complex &c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}
	Complex operator-()
	{
		Complex temp;
		temp.real = -real;
		temp.img = -img;
		return temp;
	}
	Complex operator++()
	{
		++real;
		++img;
		return (*this);
	}
	Complex operator++(int x) {
		real++;
		img++;
		return (*this);
	}
	Complex operator,(Complex c)
	{
		return c;
	}
	friend ostream & operator<<(ostream &cout, Complex c);
	friend istream & operator>>(istream &cin, Complex &c);
};

	
int main()
{
	Complex c1,c2(3,8),c3(1,5),c4(c2);
	c1 = c2 + c3;
	cout << "add:- " << endl;
	c1.display();
	c1 = c2 - c3;
	cout << "sub:- " << endl;
	c1.display();
	c1 = -c2;
	cout << "unary'-':- " << endl;
	c1.display();
	c1 = ++c4;
	cout << "pre_incr:- " << endl;
	c1.display();
	c1 = c3++;
	cout << "post_decr:- " << endl;
	c1.display();
	c1 = (c2,c3);
	cout << "','oprator:- " << endl;
	c1.display();
	cout << c2;
	cin >> c1;
	cout << c1;
	return 0;
}

ostream & operator<<(ostream &cout, Complex c)
{
	cout << "real = " << c.real << endl;
	cout << "img = " << c.img << endl;
	return cout;
}

istream & operator>>(istream &cin, Complex &c)
{
	cin >> c.real;
	cin >> c.img;
	return cin;
}

