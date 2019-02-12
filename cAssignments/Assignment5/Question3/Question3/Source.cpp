#include<stdio.h>
enum operation { sum=1 , sub , mul , div };
struct complex
{
	int real,img;
}c1, c2, c3;
int sumf();
int subf();
int mulf(complex,complex);
int divf();
int main()
{
	enum operation s;
	int i;
	printf("enter real and img values of first complex number\n");
	scanf("%d %d", &c1.real, &c1.img);
	printf("enter real and img values of second complex number\n");
	scanf("%d %d", &c2.real, &c2.img);
	printf("choose operation\n1.sum\n2.sub\n3.mul\n4.div");
	scanf("%d",&s);
	switch (s)
	{
	case sum:sumf(); break;
	case sub:subf(); break;
	case mul:mulf(c1,c2); break;
	case div:divf(); break;
	default:printf("invalid operation");
	}
	return 0;
}
int sumf()
{
	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	if (c3.img >= 0)
		printf("Sum = %d + %di", c3.real, c3.img);
	else
		printf("Sum = %d %di", c3.real, c3.img);
	return 0;
}
int subf()
{
	c3.real = c1.real - c2.real;
	c3.img = c1.img - c2.img;
	if (c3.img >= 0)
		printf("Diff = %d + %di", c3.real, c3.img);
	else
		printf("Diff = %d %di", c3.real, c3.img);
	return 0;
}
int mulf(complex c1,complex c2)
{
	c3.real = (c1.real*c2.real) - (c1.img*c2.img);
	c3.img = (c1.real*c2.img) + (c1.img*c2.real);
	if (c3.img >= 0)
		printf("Mul = %d + %di", c3.real, c3.img);
	else
		printf("Mul = %d %di", c3.real, c3.img);
	return 0;
}
int divf()
{
	complex c;
	float x,y,z;
	c3.real = (c1.real*c2.real) + (c1.img*c2.img);
	c3.img = (c1.img*c2.real) - (c1.real*c2.img);
	c2.real = (c2.real*c2.real) + (c2.img*c2.img);
	c.real = c3.real / c2.real;
	c.img = c3.img / c2.real;
	if (c.real>0&&c.img>0)
	{
		if (c.img >= 0)
			printf("Div = %d + %di", c.real, c.img);
		else
			printf("Div = %d %di", c.real, c.img);
	}
	else if (c.real > 0 && c.img==0)
	{
		if (c.img>= 0)
			printf("Div = %d + %d/%di", c.real, c3.img, c2.real);
		else
			printf("Div = %d %d/%di", c.real, c3.img,c2.real);
	}
	else if (c.real== 0 && c.img > 0)
	{
		if (c.img>= 0)
			printf("Div = %d/%d + %di", c3.real, c2.real, c.img);
		else
			printf("Div = %d %d/%di", c3.real, c2.real, c.img);
	}
	else
	{
		if (c.img>= 0)
			printf("Div = %d/%d + %d/%di", c3.real, c2.real, c3.img, c2.real);
		else
			printf("Div = %d/%d %d/%di", c3.real, c2.real, c3.img, c2.real);
	}
	return 0;
}