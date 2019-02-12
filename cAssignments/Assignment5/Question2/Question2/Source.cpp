#include<stdio.h>
struct data
{
	int num;
	char ch;
};
union udata
{
	int unum;
	char uch;
};
int main()
{
	printf("size of structure - %d bytes\n", sizeof(data));
	printf("size of union - %d bytes", sizeof(udata));
	return 0;
}