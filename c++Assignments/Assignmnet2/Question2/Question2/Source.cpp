#include<iostream>
using namespace std;
class Student
{
	int roll;
	char *name;
	int marks[6];
	int total;
	char grade;
public:
	
	friend void generate_results(Student s[], int n);
	friend ostream & operator<<(ostream &cout, Student s);
	friend istream & operator>>(istream &cin, Student &s);
};
void generate_results(Student s[], int n)
{
	int i = 0,tot;
	float avg;
	for (i = 0; i < n; i++)
	{
		cout << "enter student " << i + 1 << " details" << endl;
		cin >> s[i];
		tot = 0; 
		for (int j = 0; j < 6; j++)
		{
			tot += s[i].marks[j];
		}
		s[i].total = tot;
		avg = (float)tot / 6;
		if (avg >= 70)
		{
			s[i].grade = 'A';
		}
		else if (avg >= 60 && avg < 70)
		{
			s[i].grade = 'B';
		}
		else if (avg < 60 && avg >= 40)
		{
			s[i].grade = 'C';
		}
		else
			s[i].grade = 'D';
		cout << "displaying student " << i + 1 << " details" << endl;
		cout << s[i];
	}
}
istream & operator>>(istream &cin, Student &s)
{
	char str[50]; int i = 0;
	cout << "enter roll" << endl;
	cin >> s.roll;
	cout << "enter name" << endl;
	cin >> str;
	s.name = new char[strlen(str) + 1];
	strcpy(s.name, str);
	cout << "enter marks" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> s.marks[i];
	}
	return cin;
}
ostream & operator<<(ostream &cout, Student s)
{
	int i = 0;
	cout <<"Rollno - "<< s.roll << endl;
	cout << "Name - ";
	while ( i <= strlen(s.name))
	{
		cout << s.name[i];
		i++;
	}
	cout << endl;
	cout << "Marks - " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << s.marks[i] << endl;
	}
	cout << "Total - " << s.total << endl;
	cout << "Grade - " << s.grade << endl;
	return cout;
}
int main()
{
	Student s[3];
	generate_results(s, 3);
	}