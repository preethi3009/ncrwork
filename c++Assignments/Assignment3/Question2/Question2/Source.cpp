

#include <iostream>
using namespace std;
#define SIZE 100

template <class T>
class Stack
{
	int size;  // Number of elements on Stack
	int top;
	T* stackPtr;

public:

	//constructor with the default size 10
	Stack()
	{
		size = SIZE;
		top = -1;  // initialize stack
		stackPtr = new T[size];
	}
	
	void set_size(int s)
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

	int isEmpty() 
	{
		return top == -1;
	}

	int isFull() 
	{
		return top == size - 1; 
	}	
};


void main()
{
	typedef Stack<float> FloatStack;
	typedef Stack<int> IntStack;
	typedef Stack<char> CharStack;

	int option;
	char choice;
	
	do
	{
		cout << "enter option 1.float stack 2.int stack 3.char stack" << endl;
		cin >> option;

		int size;

		cout << "enter size of the stack" << endl;
		cin >> size;

		switch (option)
		{
		case 1: {

			FloatStack fs;
			fs.set_size(size);

			float f = 1.1;
			cout << "Pushing elements onto float stack" << endl;
			while (fs.push(f))
			{
				cout << f << ' ';
				f += 1.1;
			}
			cout << endl << "Stack Full." << endl

				<< endl << "Popping elements from float stack" << endl;
			while (fs.pop(f))
				cout << f << ' ';
			cout << endl << "Stack Empty" << endl;
			break;
		}
		case 2: {

			IntStack is;
			is.set_size(size);

			int i = 1.1;
			cout << "Pushing elements into int stack" << endl;
			while (is.push(i))
			{
				cout << i << ' ';
				i += 1;
			}
			cout << endl << "Stack Full" << endl
				<< endl << "Popping elements from int stack" << endl;
			while (is.pop(i))
				cout << i << ' ';
			cout << endl << "Stack Empty" << endl;
			break;
		}
		case 3: {

			CharStack cs;
			cs.set_size(size);

			char i = 'a';
			cout << "Pushing elements onto int stack" << endl;
			while (cs.push(i))
			{
				cout << i << ' ';
				i += 1;
			}
			cout << endl << "Stack Full" << endl
				<< endl << "Popping elements from int stack" << endl;
			while (cs.pop(i))
				cout << i << ' ';
			cout << endl << "Stack Empty" << endl;
			break;
		}
		default:
			cout << "wrong option" << endl;
		}

		cout <<endl<< "do you want to continue" << endl;
		cin >> choice;

	} while (choice=='y'||choice=='Y');
}