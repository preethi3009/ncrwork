#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
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
	void travel_bkwd(struct node *);
	void reverse();
	~list();
};
list::list() {
	start = NULL;
}
void list::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
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
int list::delete_first()
{
	int del_ele;
	if (start != NULL)
	{
		struct node *temp;
		temp = new node;
		temp = start;
		start = start->next;
		del_ele = temp->data;
		delete temp;
		return del_ele;
	}
	else
		cout << "list empty" << endl;
}
int list::delete_last()
{
	int x;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
			return x;
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
			return x;
		}
	}
	else
		cout << "list is empty" << endl;
}
void list::delete_spec(int ele)
{
	struct node *temp, *curr;
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
			while (curr->next != NULL & curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp->data = curr->data;
			}
		}
	}
}
void list::travel_frwd()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}
void list::travel_bkwd(struct node *curr)
{
	if (curr != NULL)
	{
		travel_bkwd(curr->next);
		cout << "curr->data" << endl;
	}
}
void list::reverse()
{
	struct node *rev,*temp;
	rev = new node;
	if (start != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
	}
	else
		cout << "list is empty" << endl;
}
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

int main()
{
	int i,ele;
	char ch;
	list l;
	do
	{
		cout << "1.insert first 2.insert last 3.insert before 4.insert after 5.delete first 6.delete last 7.delete specific 8.traverse forward 9.traverse backward 10.reverse the list " << endl;
		cin >> i;
		switch (i) {
		case 1: {
			cout << "enter element" << endl;
			cin >> ele;
		}

		}
		cout << "do u want to continue?y/n" << endl;
		cin >> ch;
	} while (ch);
}