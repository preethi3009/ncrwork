#include<iostream>
using namespace std;
void merge(int, int);
void sort(int, int, int);
int arr[50];
int main()
{
	int n,i,low,high,mid;
	cout << "enter array size" << endl;
	cin >> n;
	low = 0;
	high = n-1;
	cout << "enter array elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mid = (low + high) / 2;
	merge(low, mid);
	merge(mid+1, high);
	sort(low, mid, high);
	cout << "sorted elements are" << endl;
	for (i = 0; i < n; i++)
		cout << arr[i] << endl;
	return 0;
}
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
void sort(int l1s, int l1e, int l2e)
{
	int l2s = l1e + 1;
	int *l3, i, j, k;
	l3 = new int[l2e - l1e + 1];
	i = l1s;
	j = l2s;
	k = 0;
	while (i <l1e&&j<l2e)
	{
		if(arr[i] > arr[j])
		{
			l3[k++] = arr[j++];
		}
		else
		{
			l3[k++] = arr[i++];
		}
	}
	while(i <l1e)
	{
		l3[k++] = arr[i++];
	}
	while(j < l2e)
	{
		l3[k++] = arr[j++];
	}
	while (l2e <= l1e)
	{
		arr[l2e--] = l3[k--];
		delete l3;
	}

}