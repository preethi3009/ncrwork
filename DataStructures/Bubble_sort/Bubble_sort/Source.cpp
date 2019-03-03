#include<iostream>

using namespace std;

int main()
{
	int i,j, arr[30], arr_size;
	int temp;

	cout << "enter array size" << endl;
	cin >> arr_size;
	
	cout << "enter array elements" << endl;
	for (i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}

	for (i = 0; i < arr_size-1 ; i++)
	{
		int flag = 0;

		for (j = 0; j < arr_size -i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
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
	for (i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}