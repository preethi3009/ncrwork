#include<iostream>
using namespace std;
int main()
{
	int i, j, arr[30],n,loc,min=0,temp;
	cout << "enter array size" << endl;
	cin >> n;
	cout << "enter array elements" << endl;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++)
	{
		loc = i;
		j = i+1;
		while (j < n)
		{
			if (arr[loc] > arr[j])
				loc = j;
			j++;
		}
		temp = arr[loc];
		arr[loc] = arr[i];
		arr[i] = temp;
	}
	cout << "sorted elements are" << endl;
	for (i = 0; i < n; i++)
	{
		cout << arr[i]<<endl;
	}
	return 0;
}