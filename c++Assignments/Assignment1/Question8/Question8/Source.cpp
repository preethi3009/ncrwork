#include<iostream>
using namespace std;
class Employee
{
	int eid;
	int sal;
public:
	Employee()
	{
		eid = 0;
		sal = 0;
		cout << "deafault constructor" << endl;

	}
	Employee(int x, int y)
	{
		eid = x;
		sal = y;
		cout << "In parameterised constructor" << endl;
	}
	Employee(Employee &e)
	{
		eid = e.eid;
		sal = e.sal;
		cout << "In copy constructor" << endl;
	}
	void display()
	{
		cout << "id = " << eid << "sal = " << sal << endl;
	}
	friend void incr(Employee e);
	friend void incr_ref(Employee &e);
	~Employee()
	{
		cout << "in destructor" << endl;
	}
};
void incr(Employee e)
{
	cout << "call by value" << endl;
	cout << "incrementing sal " << endl;
	e.sal = e.sal + e.sal / 10;
}
void incr_ref(Employee &e)
{
	cout << "call by reference" << endl;
	e.sal = e.sal + e.sal / 10;
}
int main()
{
	Employee e1(100,5000),e2,e3(e1);
	cout << "before increment" << endl;
	e1.display();
	cout << "after increment by val" << endl;
	incr(e1);
	e1.display();
	incr_ref(e1);
	cout << "after increment by ref" << endl;
	e1.display();
}