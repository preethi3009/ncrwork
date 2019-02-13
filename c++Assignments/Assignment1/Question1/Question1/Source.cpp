#include<iostream>
using namespace std;
class Time
{
	int hours;
	int mins;
	int secs;
public:
	Time()
	{
		hours = 0;
		mins = 0;
		secs = 0;
	}
	Time(int h, int m, int s)
	{
		hours = h;
		mins = m;
		secs = s;
	}
	void display()
	{
		cout << hours << ":" << mins << ":" << secs;
	}
	void add(Time &t1, Time &t2)
	{
		hours = t1.hours + t2.hours;
		mins = t1.mins + t2.mins;
		secs = t1.secs + t2.secs;
	}
};
int main()
{
	Time t, t1(10, 22, 17), t2(2, 11, 16);
	t.add(t1, t2);
	t.display();
	return 0;
}