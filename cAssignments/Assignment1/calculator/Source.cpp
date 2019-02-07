#include<stdio.h>
int res = -1;
int main()
{
	int a, b;
	printf("enter operands\n");
	scanf("%d%d", &a, &b);
	res = add(a, b);
	printf("add=%d", res);
	res = sub(a, b);
	printf("sub=%d", res);
	res = mul(a, b);
	printf("mul=%d", res);
	res = div(a, b);
	printf("div=%d", res);
	return 0;

}