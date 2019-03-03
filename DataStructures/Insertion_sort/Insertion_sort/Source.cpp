#include<iostream>

using namespace std;

int main()
{
	int i,j,arr[50],arr_size,temp;
	
	cout << "enter array size" << endl;
	cin >> arr_size;
	
	cout << "enter array elements" << endl;
	for (i = 0; i < arr_size; i++)
		cin >> arr[i];

	for (i = 1; i < arr_size; i++)
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
	for (i = 0; i < arr_size; i++)
		cout << arr[i] << endl;

	return 0;
}