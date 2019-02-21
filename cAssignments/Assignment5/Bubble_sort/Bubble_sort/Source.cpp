#include<iostream>
using namespace std;
int main()
{
	int i,j, arr[30], n;
	cout << "enter array size" << endl;
	cin >> n;
	cout << "enter array elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n-1 ; i++)
	{
		int flag = 0;
		for (j = 0; j < n -i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
			
		}
		if (flag == 0)
			break;
	}
	cout << "sorted array : " << endl;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}