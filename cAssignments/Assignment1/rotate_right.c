#include<stdio.h>

#include<math.h>

long int rotate_right(long int n,int b);

int main()

{

	long int n,res;

	int p;

	printf("enter num");

	scanf("%ld",&n);

	printf("enter pos");

	scanf("%d",&p);

	res = rotate_right(n, p);

	printf("%ld", res);

	return 0;

}

long int rotate_right(long int n, int b)

{

	int i = 0, j = 1,m=0,r=0;

	for (i = 0; i < b; i++)

	{

		r = n % 10;

		n = n / 10;

		m = m + (j*r);

		j = j * 10;

	}

	b = 0;

	int num = n;

	while (num != 0)

	{

		num = num / 10;

		b++;

	}

	n = m*pow(10, b) + n;

	return n;



}