#include<iostream>

using namespace std;

int *arr;

void merge(int , int );
void sort(int , int , int );

//main function
int main()
{
	int arr_size,i;

	cout << "enter array size" << endl;
	cin >> arr_size;

	//allocating memory to the array
	arr = new int[arr_size];

	//input from user
	cout << "enter array elements" << endl;
	for (i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}

	merge(0,arr_size-1);

	//displaying sorted array
	cout << "sorted elements are" << endl;
	for (i = 0; i < arr_size; i++)
		cout << arr[i] << endl;

	return 0;
}

//function for dividing the array
void merge(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge(low, mid);
		merge(mid + 1, high);
		sort(low, mid, high);
	}
}

//function for sorting and merging the arrays
void sort(int list1Start, int list1End, int list2End)
{
	int list2Start = list1End + 1;
	int *list3, list1Index, list2Index, list3Index;

	//creating memory for list3
	list3 = new int[list2End - list1End + 1];

	list1Index = list1Start;//for traversing through list1
	list2Index = list2Start;//for traversing through list2
	list3Index = 0;//for traversing through list3


	while (list1Index <= list1End&&list2Index <= list2End)
	{
		if (arr[list1Index] > arr[list2Index])
		{
			list3[list3Index++] = arr[list2Index++];
		}
		else
		{
			list3[list3Index++] = arr[list1Index++];
		}
	}
	while (list1Index <= list1End)
	{
		list3[list3Index++] = arr[list1Index++];
	}
	while (list2Index <= list2End)
	{
		list3[list3Index++] = arr[list2Index++];
	}
	while (list2End >= list1End)
	{
		arr[list2End--] = list3[--list3Index];
	}

}

