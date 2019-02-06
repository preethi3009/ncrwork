#include<stdio.h>
int main()
{
	int sal,gross_sal=0;
	printf("enter sal\n");
	scanf("%d", &sal);
	if (sal > 0 && sal <= 4000)
		gross_sal = sal + (sal / 10) + (sal / 2);
	else if (sal > 4000 && sal <= 8000)
		gross_sal = sal + (sal / 5) + (3 * sal / 5);
	else if (sal > 8000 && sal < 12000)
		gross_sal = sal + (sal / 4) + (7 * sal / 10);
	else
		gross_sal = sal + (3 * sal / 10) + (4 * sal / 5);
	printf("gross sal is %d", gross_sal);
	return 0;
}