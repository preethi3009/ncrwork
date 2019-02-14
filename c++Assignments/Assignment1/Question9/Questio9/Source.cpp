#include<iostream>
using namespace std;
void swap_value(int i, int j)
{
	i = i + j;
	j = i - j;
	i = i - j;
	cout << "swapped values before return i= " << i << " j= " << j << endl;
}
void swap_reference(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "swapped values before return i= " << a << " j= " << b << endl;
}
int main()
{
	int i, j,n;
	cout << "enter i and j";
	cin >> i >> j;
	cout << "enter ur choice"<<endl;
	cout << "1.swap by value" << endl;
	cout << "2.swap by reference" << endl;
	cin >> n;
	switch (n)
	{
	case 1:swap_value(i, j);
		cout << "swapped values after return i = " << i<<" j = " << j;
		break;
	case 2:swap_reference(i,j);
		cout << "swapped values after return i = " << i << " j = " << j;
		break;
	default:cout << "invalid option";
	}
}
