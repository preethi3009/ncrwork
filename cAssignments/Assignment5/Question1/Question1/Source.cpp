#include<stdio.h>
struct time
{
	int hours;
	int mins;
	int secs;
}t;
int main()
{
	printf("enter hours\n");
	scanf("%d", &t.hours);
	printf("enter minutes\n");
	scanf("%d", &t.mins);
	printf("enter seconds\n");
	scanf("%d", &t.secs);
	if (t.hours > 24 || t.mins > 60 || t.secs > 60)
		printf("invalid time");
	else
		printf("%d:%d:%d", t.hours, t.mins, t.secs);
	return 0;
}