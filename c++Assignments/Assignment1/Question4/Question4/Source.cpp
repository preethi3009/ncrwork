#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return (a + b);
}
inline int sub(int a, int b)
{
	return (a - b);
}
inline long int mul(int a, int b)
{
	return (a, b);
}
inline float div1(float a, float b)
{
	return (a / b);
}
int main()
{
	int a, b;
	cout << "enter a & b " << endl;
	cin >> a >> b;
	cout << "add - " << add(a, b) << endl;
	cout << "sub - " << sub(a, b) << endl;
	cout << "mul - " << mul(a, b) << endl;
	cout << "div - " << div1(a, b) << endl;
}