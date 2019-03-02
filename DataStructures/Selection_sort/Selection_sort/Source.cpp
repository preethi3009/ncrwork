#include<iostream>
using namespace std;

//main function
int main()
{
	int i, j, array[30],array_size,loc,min=0,temp;
	
	cout << "enter array size" << endl;
	cin >> array_size;//size of the array
	
	cout << "enter array elements" << endl;
	for (i = 0; i < array_size; i++)
		//array elemnts to be sorted - input from user
		cin >> array[i];
	
	for (i = 0; i < array_size; i++)//traversing through the array
	{
		//i=index pointing to the first element of the array that is unsorted
		//j=index pointing to the next element of i in the array
		//loc=index pointing to the shortest element in the list
		loc = i;
		j = i+1;

		while (j < array_size)
		{
			//finding the shortest element
			if (array[loc] > array[j])
				loc = j;
			j++;
		}

		//swapping i and loc
		temp = array[loc];
		array[loc] = array[i];
		array[i] = temp;
	}

	//printing sorted array
	cout << "sorted elements are" << endl;
	for (i = 0; i < array_size; i++)
	{
		cout << array[i]<<endl;
	}
	return 0;
}