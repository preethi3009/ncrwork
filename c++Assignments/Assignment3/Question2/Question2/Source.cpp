

#include <iostream>
using namespace std;

template <class T>
class Stack
{
	int size;  // Number of elements on Stack
	int top;
	T* stackPtr;

public:

	//constructor with the default size 10
	Stack(int s)
	{
		size = s > 0 && s < 1000 ? s : 10;
		top = -1;  // initialize stack
		stackPtr = new T[size];
	}
	
	// push an element onto the Stack 
	int push(const T& item)
	{
		if (!isFull())
		{
			stackPtr[++top] = item;
			return 1;  // push successful
		}
		return 0;  // push unsuccessful
	}

	// pop an element off the Stack
	int pop(T& popValue)
	{
		if (!isEmpty())
		{
			popValue = stackPtr[top--];
			return 1;  // pop successful
		}
		return 0;  // pop unsuccessful
	}
	int isEmpty()const { return top == -1; }
	int isFull() const { return top == size - 1; }	
};


void main()
{
	typedef Stack<float> FloatStack;
	typedef Stack<int> IntStack;
	typedef Stack<char *> charstk;

	charstk cs(2);
	char *s;
	FloatStack fs(5);
	float f = 1.1;
	cout << "Pushing elements onto fs" << endl;
	while (fs.push(f))
	{
		cout << f << ' ';
		f += 1.1;
	}
	cout << endl << "Stack Full." << endl
		<< endl << "Pop0ping elements from fs" << endl;
	while (fs.pop(f))
		cout << f << ' ';
	cout << endl << "Stack Empty" << endl;
	cout << endl;

	IntStack is(2);
	int i = 1.1;
	cout << "Pushing elements onto is" << endl;
	while (is.push(i))
	{
		cout << i << ' ';
		i += 1;
	}
	cout << endl << "Stack Full" << endl
		<< endl << "Popping elements from is" << endl;
	while (is.pop(i))
		cout << i << ' ';
	cout << endl << "Stack Empty" << endl;
}