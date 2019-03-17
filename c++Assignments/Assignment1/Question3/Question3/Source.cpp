
//Write a C++ program to add two complex numbers.The class Complex contains
//three constructors.
//a.One with no parameter.
//b.With one parameter(Same value for real and imaginary part)
//c.With two parameters.
//d.A friend functions
//i.One to add two complex number by taking two reference variables of
//the class complex.
//ii.One to multipy two complex number by taking two reference
//variables of class complex

#include<iostream>
using namespace std;

//complex number class
class Complex
{
	int real, img;

public:

	//default constructor
	Complex()
	{
		real = 0;
		img = 0;
	}

	//constructor with a single parameter - same value for both real and img part
	Complex(int a)
	{
		real = a;
		img = a;
	}

	//constructor with two parameters
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}

	//sets user provided values
	void set_val(int a, int b)
	{
		real = a;
		img = b;
	}
	//displaying complex number
	void display()
	{
		if(img<0)
			cout << real<< img << "i" << endl;
		else
			cout << real << "+" << img << "i"<<endl;
	}

	//friend functions for adding and multiplying complex numbers
	friend Complex add(Complex, Complex);
	friend Complex mul(Complex, Complex);

};

//adding two complex numbers
Complex add(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}

//multiplying two complex numbers
Complex mul(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = (c1.real*c2.real) - (c1.img*c2.img);
	temp.img = (c1.real*c2.img) + (c1.img*c2.real);
	return temp;
}

//main function
int main()
{
	int real, img ,option ;
	char choice;
	Complex c,c1(3), c2(1,2),complex1,complex2;

	do
	{
		cout << "enter real and img values of first complex number" << endl;
		cin >> real;
		cin >> img;

		complex1.set_val(real, img);

		cout << "enter real and img values of second complex number" << endl;
		cin >> real;
		cin >> img;

		complex2.set_val(real, img);

		cout << "enter your choice 1.addition 2.multiplication" << endl;
		cin >> option;

		switch (option)
		{
		case 1: {
			c = add(complex1, complex2);
			c.display();
			break;
		}
		case 2: {
			c = mul(complex1, complex2);
			c.display();
			break;
		}
		default:
			cout << "wrong operation" << endl;
		}
				cout << "do you want to continue?y/n" << endl;
				cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	return 0;
}