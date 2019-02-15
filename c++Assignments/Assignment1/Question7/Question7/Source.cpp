#include<iostream>
using namespace std;
class Matrix
{
	int rows;
	int cols;
	int **arr;
public:
	Matrix()
	{
		rows = 0;
		cols = 0;
		arr = NULL;
	}
	Matrix(int m, int n)
	{
		rows = m;
		cols = n;
		arr = new int *[rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new int[cols];
	}
	void intialize()
	{
		cout << "enter matrix values" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> (*(*(arr + i) + j));
			}
		}
	}
	void display()
	{
		cout << "displaying matrix values" << endl;
		for(int i=0;i<rows;i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << (*(*(arr + i) + j));
			}
			cout << endl;
		}
	}
	void multiply(Matrix m1, Matrix m2)
	{
		int sum = 0;
		rows = m1.rows;
		cols = m2.cols;
		arr = new int *[rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new int[cols];
		for (int c = 0; c < m1.rows; c++) {
			for (int d = 0; d < m1.cols; d++) {
				for (int k = 0; k < m2.rows; k++) {
					sum = sum + (*(*(m1.arr+c)+k)) * (*(*(m2.arr+k)+d));
				}

				(*(*(arr+c)+d)) = sum;
				sum = 0;
			}
		}
	}

};
int main()
{
	Matrix m1(2,2), m2(2,2),m3;
	m1.intialize();
	m1.display();
	m2.intialize();
	m2.display();
	m3.multiply(m1, m2);
	m3.display();
}