#include<iostream>
using namespace std;
class Employee
{
	int empno;
	char *name;
	int sal;
public:
	Employee()
	{
		empno = 0;
		name = NULL;
		sal = 0;
	}
	Employee(int n,const char s[],int a)
	{
		empno = n;
		int l = strlen(s) + 1;
		name = new char[l];
		strcpy(name, s);
		sal = a;
	}
	Employee(const Employee &e)
	{
		empno = e.empno;
		name = new char[strlen(e.name) + 1];
		sal = e.sal;
	}
	void set_data(int n,const char s[], int a)
	{
		empno = n;
		name = new char[strlen(s) + 1];
		strcpy(name, s);
		sal = a;
	}
	void read_data()
	{
		int i = 0;
		cout << "Empno - " << empno << endl;
		cout << "Name - "<< name<<endl;
		cout << "Salary - " << sal << endl;
	}
	~Employee()
	{
		if (name != NULL)
			free(name);
	}
	friend istream & operator>>(istream &cin, Employee &e);
};
istream & operator>>(istream &cin, Employee &e)
{
	char str[50];
	cout << "enter empno - " << endl;
	cin >> e.empno;
	cout << "enter name - " << endl;
	cin >> str;
	e.name = new char[strlen(str) + 1];
	strcpy(e.name, str);
	cout << "enter salary -" << endl;
	cin >> e.sal;
	return cin;
}
int main()
{
	Employee e[3],e1, e2(102, "ram", 5000);
	e1.set_data(101, "shyam", 6500);
	e1.read_data();
	e2.read_data();
	for (int i = 0; i < 3; i++)
	{
		cin >> e[i];
		cout << "Employee " << i+1 << " details" << endl;
		e[i].read_data();
	}
}