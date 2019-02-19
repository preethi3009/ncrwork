#include<iostream>
#include<string>
using namespace std;
class String {
	char *sptr;
	int len;
public:
	String()
	{
		sptr = NULL;
		len = 0;
	}
	String(const char *s)
	{
		len = strlen(s);
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, s);
	}
	String(const String &temp)
	{
		len = temp.len;
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, temp.sptr);
	}
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
	String operator=(String s)
	{
		len = s.len;
		if (sptr != NULL)
			free(sptr);
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy(sptr, s.sptr);
		return (*this);
	}
	char& operator[](int n)
	{
		if (n > len)
			cout << "out of bound";
		else
			return sptr[n];
	}
	String operator+(String s)
	{
		String temp;
		temp.len = len + s.len;
		temp.sptr = (char *)malloc(sizeof(char)*(len + 1));;
		strcpy(temp.sptr, sptr);
		strcat(temp.sptr, s.sptr);
		return (temp);
	}
	~String()
	{
	if (sptr != NULL)
      free(sptr);
		 }
	
	friend ostream & operator<< (ostream &cout, String s);
	friend istream & operator>>(istream &cin, String &s);

};
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
	String s1, s2("apple"),s3("fruit"),s4(s2);
	s2.display();
	cin >> s1;
	cout << s1;
	s4[2] = 'z';
	cout << s4;
	cout << s3[3] << endl;;
	s1 = s2 + s3;
	cout << s1;
}