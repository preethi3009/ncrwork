
//Define string class with dynamic memory allocation for string.Define default
//constructor, parameterized constructors, copy constructor, destructor, Overload + ,
//[], =, << , >> operators.Observe the behavior of shallow copying and deep copying.

#include<iostream>
#include<string>
using namespace std;

//class for strings
class String {

	char *sptr;//pointer to the string
	int len;//length of the string

public:

	//default constructor
	String()
	{
		sptr = NULL;
		len = 0;
	}

	//parameterized constructor
	String(const char *s)
	{
		len = strlen(s);
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, s);
	}

	//copy constructor
	String(const String &temp)
	{
		len = temp.len;
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
	}

	//set string
	void set_string(char *s)
	{
		len = strlen(s);
		sptr = (char *)malloc(sizeof(char)*len + 1);
		strcpy(sptr, s);
	}

	//displaying a string
	void display()
	{
		int i = 0;
		while (i <= len)
		{
			cout << sptr[i];
			i++;
		}
		cout << endl;
	}

	//operator overloading =
	String operator=(String s)
	{
		len = s.len;

		if (sptr != NULL)
			free(sptr);
		
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, s.sptr);
		
		return (*this);
	}

	//operator overloading []
	char& operator[](int n)
	{
		if (n > len)
			cout << "out of bound";
		else
			return sptr[n];
	}

	//operator overloading +
	String operator+(String s)
	{
		String temp;
		temp.len = len + s.len;
		temp.sptr = (char *)malloc(sizeof(char)*(len + 1));;
		strcpy(temp.sptr, sptr);
		strcat(temp.sptr, s.sptr);
		return (temp);
	}

	//destructor
	~String()
	{
		if (sptr != NULL)
		  free(sptr);
	}
	
	//friend functions for overloading >> and <<
	friend ostream & operator<< (ostream &cout, String s);
	friend istream & operator>>(istream &cin, String &s);

};

//<< overloading
ostream & operator<< (ostream &cout, String s)
{
	int i = 0;
	while (i <= s.len)
	{
		cout << s.sptr[i];
		i++;
	}
	cout << endl;
	return cout;
}

//>> overloading
istream & operator>>(istream &cin,String &s)
{
	char str[20];
	cin >> str;

	s.len = strlen(str);
	s.sptr = new char[s.len];
	strcpy(s.sptr, str);
	
	return cin;
}
int main()
{
	int option;
	char choice;
	char str[50];
	String string1, string2, string3;
	
	do
	{
		cout << "enter string1" << endl;
		cin >> str;
		string1.set_string(str);

		cout << "enter a option 1.display 2.concatenation 3.[]operation" << endl;
		cin >> option;

		switch (option)
		{
		case 1: {
			cout << string1;
			break;
		}
		case 2: {
			
			cout << "enter string2 " << endl;
			cin >> string2;

			string3 = string1 + string2;
			
			cout << "concatenated string is ";
			cout << string3 << endl;
			
			break;
		}
		case 3: {
			int i;
			char ch;
			
			cout << "enter index" << endl;
			cin >> i;
			
			if (i > strlen(str))
			{
				cout << "out of bound" << endl;
				break;
			}
			else
			{
				cout << string1[i];			
				cout << "enter a charcter" << endl;
				cin >> ch;

				string1[i] = ch;
				cout << string1 << endl;
			}
			break;
		}
		default:
			cout << "wrong operation" << endl;
			break;
		}
		
		cout << "do you want to continue?y/n" << endl;
		cin >> choice;
	
	} while (choice == 'y' || choice == 'Y');
	
	return 0;
}