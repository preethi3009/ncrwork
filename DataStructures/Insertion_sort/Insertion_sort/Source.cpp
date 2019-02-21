#include<iostream>
using namespace std;
int main()
{
	int i,j,arr[50],n,temp;
	cout << "enter array size" << endl;
	cin >> n;
	cout << "enter array elements" << endl;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		temp = arr[i];
		while (j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	cout << "sorted elements are : " << endl;
	for (i = 0; i < n; i++)
		cout << arr[i] << endl;
	return 0;
}