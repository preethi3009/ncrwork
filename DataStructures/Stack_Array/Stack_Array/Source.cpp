#include<iostream>

using namespace std;

//structure for a stack
struct stack
{
	int *stack_arr;
	int top;
	int size;
};

//stack class
class _stack_
{
	struct stack stack_struct_ins;
public:
	_stack_();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void setSize(int);
	void display();
	~_stack_();
};

//default constructor
_stack_::_stack_()
{
	stack_struct_ins.top = -1;
	stack_struct_ins.stack_arr = NULL;
	stack_struct_ins.size = 0;
}

//creating the stack of given size
void _stack_::setSize(int n)
{
	stack_struct_ins.size = n;
	stack_struct_ins.stack_arr = new int[n];
}

//function for checking whether stack is full or not
bool _stack_::isFull()
{
	//checking whether the stack size and top of the stack are equal or not
	return (stack_struct_ins.top == (stack_struct_ins.size - 1));
}

//function for checking whether the stack is empty or not
bool _stack_::isEmpty()
{
	//if top of the stack is -1 then stack is empty
	return (stack_struct_ins.top == -1);
}

//pushing an element to the stack
void _stack_::push(int ele)
{
	if (!isFull())
		//increment top and then insert element
		stack_struct_ins.stack_arr[++stack_struct_ins.top] = ele;
	else
		cout << "stack is full" << endl;
}

//popping an element from the stack
int _stack_::pop()
{
	int x = -999;
	if (!isEmpty())
		//decrement the top
		x = stack_struct_ins.stack_arr[stack_struct_ins.top--];
	else
		cout << "stack is empty"<<endl;
	return x;
}

//returns the top element of the stack
int _stack_::peek()
{
	int x = -999;
	if (!isEmpty())
		x = stack_struct_ins.stack_arr[stack_struct_ins.top];
	else
		cout << "empty" << endl;
	return x;
}

//display the stack contents
void _stack_::display()
{
	if (isEmpty())
		cout << "stack is empty" << endl;
	else
	{
		cout << "displaying stcak elements" << endl;
		for (int i = stack_struct_ins.top; i >= 0; i--)
		{
			cout << stack_struct_ins.stack_arr[i] << endl;
		}
	}
}

//default destructor
_stack_::~_stack_()
{
	delete stack_struct_ins.stack_arr;
}


//main function
int main()
{
	_stack_ stack_obj;//stack object
	int i,ele,res;
	char ch;

	//do the operation untill user want to continue
	do
	{
		cout << "chose a stack operation" << endl;
		cout << "1.setSize 2.push 3.pop 4.peek 5.display" << endl;
		cin >> i;

		switch (i)
		{
		case 1:
		{
			cout << "enter the size of the stack" << endl;
			cin >> ele;
			stack_obj.setSize(ele);
			break;
		}
		case 2:
		{
			cout << "enter ele to push" << endl;
			cin >> ele;
			stack_obj.push(ele);
			break;
		}
		case 3:
		{
			res = stack_obj.pop();
			if(res!=-999)
			cout << "popped ele is " << res << endl;
			break;
		}
		case 4:
		{
			res = stack_obj.peek();
			if(res!=-999)
			cout << "top of the stack is " << res << endl;
			break;
		}
		case 5:
		{
			stack_obj.display();
			break;
		}
		default:cout << "wrong operation" << endl;
			break;
		}
		cout << "do you want to continue? y/n " << endl;
		cin >> ch;
	} while (ch == 'y');

	return 0;
}