#include<iostream>

using namespace std;

//node structure
struct node
{
	int data;
	struct node *next;
};

//linked list class
class list
{
	struct node *start;
public:
	list();
	void insert_first(int);
	void insert_last(int);
	void insert_before(int, int);
	void insert_after(int, int);
	int delete_first();
	int delete_last();
	void delete_spec(int);
	void travel_frwd();
	void travel_bkwd();
	void reverse();
	friend void print(struct node *curr);
	~list();
};

//default constructor
list::list() {
	start = NULL;
}

//inserting element at the start of the list
void list::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}

//inserting element at the end of the list
void list::insert_last(int ele)
{
	struct node *temp,*curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start= temp;
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

//inserting element before a given key element
void list::insert_before(int key, int ele)
{
	if (start->data == key)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = start;
		start = temp;
	}
	else
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL && curr->next->data != key)
		{
			curr = curr->next;
		}
		if (curr->next != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found" << endl;
	}
}

//insert element after given key element
void list::insert_after(int key, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != key)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found" << endl;
	}
	else
		cout << "list does'nt exist" << endl;
}

//deleting first element from the list
int list::delete_first()
{
	int del_ele=-999;
	if (start != NULL)
	{
		struct node *temp;
		temp = new node;
		temp = start;
		start = start->next;
		del_ele = temp->data;
		delete temp;
	}
	else
		cout << "list empty" << endl;
	return del_ele;
}

//deleting the last element from the list
int list::delete_last()
{
	int x=-999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "list is empty" << endl;
	return x;
}

//delete a specific element in the list
void list::delete_spec(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp->data = ele;
			start = start->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp->data = curr->next->data;
				temp->next = curr->next->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "ele not found" << endl;
		}
	}
	else
		cout << "list is empty" << endl;
}

//traversing forward through the list
void list::travel_frwd()
{
	struct node *curr;
	curr = start;
	if (start != NULL)
	{
		while (curr != NULL)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
	else
		cout << "empty list" << endl;
}

//friend function for printing the elements in backward 
void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << endl;
	}
}

//traversing the list in backwards
void list::travel_bkwd()
{
	if (start != NULL)
		print(start);
	else
		cout << "empty list" << endl;
}

//destructor
list::~list()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}

//main
int main()
{
	int i,ele,key;
	char ch;
	list l;
	do
	{
		cout << "1.insert first 2.insert last 3.insert before 4.insert after 5.delete first 6.delete last 7.delete specific 8.traverse forward 9.traverse backward" << endl;
		cin >> i;
		switch (i) {
		case 1: {
			cout << "enter element" << endl;
			cin >> ele;
			l.insert_first(ele);
			break;
		}
		case 2: {
			cout << "enter element" << endl;
			cin >> ele;
			l.insert_last(ele);
			break;
		}
		case 3:
		{
			cout << "enter a ele in the list to insert before" << endl;
			cin >> key;
			cout << "enter ele to insert" << endl;
			cin >> ele;
			l.insert_before(key, ele);
			break;
		}
		case 4:
		{
			cout << "enter a ele in the list to insert after" << endl;
			cin >> key;
			cout << "enter ele to insert" << endl;
			cin >> ele;
			l.insert_after(key, ele);
			break;
		}
		case 5:
		{
			key = l.delete_first();
			if (key != -999)
				cout << "deleted ele is " << key << endl;
			break;
		}
		case 6:
		{
			key = l.delete_last();
			if (key != -999)
				cout << "deleted ele is " << key << endl;
			break;
		}
		case 7: {
			cout << "enter ele to delete" << endl;
			cin >> ele;
			l.delete_spec(ele);
			break;
		}
		case 8:
		{
			cout << "traversing forward:" << endl;
			l.travel_frwd();
			break;
		}
		case 9:
		{
			cout << "traversing backward:" << endl;
			l.travel_bkwd();
			break;
		}
		default: {
			cout << "wrong operation" << endl;
			break;
		}
		}
		cout << "do u want to continue?y/n" << endl;
		cin >> ch;
	} while (ch=='y'||ch=='Y');
}