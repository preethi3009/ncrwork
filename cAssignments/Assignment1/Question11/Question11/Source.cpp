#include<stdio.h>
#include<math.h>
int main()
{
	long int p = 500000, n = 10;
	float si, ci,r,cal;
	printf("enter rate of interest\n");
	scanf("%f", &r);
	si = (p*n*r) / 100;
	printf("simple interest: %f\n", si);
	cal = r / 100;
	ci =p * pow((1 + cal), n);
	printf("compound interest:\nannually: %f\n", ci);
	cal = (r/2) / 100;
	ci = p * pow((1 + cal), 2*n);
	printf("halfyearly:\t%f\n", ci);
	cal = (r/4) / 100;
	ci = p * pow((1 + cal),4*n);
	printf("quarterly:\t%f\n", ci);
	cal = (r/12) / 100;
	ci = p * pow((1 + cal), 12 *n);
	printf("monthly:\t%f\n", ci);
	cal = (r/365) / 100;
	ci = p * pow((1 + cal),365 * n);
	printf("daily:\t%f\n", ci);

	return 0;
}