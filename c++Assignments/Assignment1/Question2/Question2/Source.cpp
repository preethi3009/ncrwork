#include<iostream>
#include<string>
using namespace std;
class Student
{
	char *studentName;
	char grade;
	int m1, m2, m3;
	float avg;
public:
	void set_Data(char *s, int a1, int a2, int a3)
	{
		studentName = (char *)(malloc(sizeof(char)*(strlen(s) + 1)));
		strcpy(studentName, s);
		m1 = a1;
		m2 = a2;
		m3 = a3;
	}
	void calculateAverage()
	{
		avg = m1 + m2 + m3;
		avg=(float)avg / 3;
			}
	void computeGrade()
	{
	
		if (avg > 60)
			grade = 'A';
		else if (avg > 50 && avg < 60)
			grade = 'B';
		else if (avg > 40 && avg < 50)
			grade = 'C';
		else
			grade = 'F';
	}
	void display()
	{
		cout << "name "<<studentName << endl;
		cout <<"grade "<< grade << endl;
		cout << "marks " << m1 <<" "<< m2<<" " << m3;
	}
};
int main()
{
	Student s1;
	char name[20];
	cout<<"enter name";
	cin>>name;
	s1.set_Data(name, 100, 100, 100);
	s1.calculateAverage();
	s1.computeGrade();
	s1.display();
}