#include<iostream>
#include<algorithm>

using namespace std;

//node structure
struct node
{
	int data;
	struct node *right;//right child
	struct node *left;//left child
};

//binary search tree class
class __BST__
{
	struct node *start;
public:
	__BST__();
	node *insert(int, node *);
	node * del_ele(int,node *);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	int findmax(node *);
	int findmin(node *);
	int height(node *);
	int noofleafnodes(node *);
	int noofnonleafnodes(node *);
	~__BST__();
};

//default constructor
__BST__::__BST__()
{
	start = NULL;
}

//insert a node
node *__BST__::insert(int ele,struct node *curr)
{
	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	else
	{
		//insert element towards left if it is less than the parent
		if (ele < curr->data)
			curr->left = insert(ele, curr->left);

		//else insert element towards right
		else
			curr->right = insert(ele, curr->right);
		
		return curr;
	}
}

//find max element from the tree
int __BST__::findmax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
		{
			curr = curr->right;
		}
		//right most element of the tree
		return (curr->data);
	}

	return -1;
}

//find min element in the tree
int __BST__::findmin(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		//left most element of the tree
		return (curr->data);
	}

	return -1;
}

//returns no of leaf nodes in the tree
int __BST__::noofleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	
	if (curr->left == NULL && curr->right == NULL)
		return 1;

	return (noofleafnodes(curr->left) + noofleafnodes(curr->right));
}

//returns no of non leaf nodes in the tree
int __BST__::noofnonleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	
	return (noofnonleafnodes(curr->left) + noofnonleafnodes(curr->right)+1);
}

//returns height of the tree
int __BST__::height(struct node *curr)
{
	//height of null node is -1
	if (curr == NULL)
		return -1;
	else
		return(max(height(curr->left), height(curr->right)) + 1);
}

//inorder traversal
void __BST__::inorder(struct node *curr)
{
	if (curr != NULL)
	{
		inorder(curr->left);//left child
		cout << curr->data << endl;//root
		inorder(curr->right);//right child
	}
}

//preorder traversal
void __BST__::preorder(struct node *curr)
{
	if (curr != NULL)
	{
		cout << curr->data << endl;//root
		preorder(curr->left);//left child
		preorder(curr->right);//right child
	}
}

//postorder traversal
void __BST__::postorder(struct node *curr)
{
	if (curr != NULL)
	{
		postorder(curr->left);//left child
		postorder(curr->right);//right child
		cout << curr->data << endl;//root
	}
}

//delete a given element from the tree
node * __BST__::del_ele(int ele, struct node *curr)
{
	if (curr != NULL)
	{
		//if element is more than the current node data, search in the right subtree
		if (ele > curr->data)
			curr->right = del_ele(ele, curr->right);

		//if element is less than the current node data,search in the left sub tree
		else if (ele < curr->data)
			curr->left = del_ele(ele, curr->left);

		//if element is equal to the current node data
		else
		{
			if (curr->left != NULL && curr->right != NULL)
			{
				curr->data = findmax(curr->left);
				curr->left = del_ele(curr->data, curr->left);
			}
			else
			{
				struct node *temp;
				temp = curr;
				if (curr->left == NULL)
					curr = curr->right;
				else
					curr = curr->left;
				delete temp;
			}
		}
	}
	return curr;
}


//main function
int main()
{
	struct node *curr;
	__BST__ bst;
	int i,ele,res;
	char ch;
	do
	{
		cout << "choose an operation" << endl;
		cout << "1.insert 2.delete 3.findmax 4.findmin 5.height 6.preorder 7.postorder 8.inorder 9.no of leaf nodes 10.no of non leaf nodes" << endl;
		cin >> i;
		switch (i)
		{
		case '1': {
			cout << "enter an element to insert" << endl;
			cin >> ele;
			bst.insert(ele, curr);
			break;
		}
		case '2': {
			cout << "enter a element to delete" << endl;
			cin >> ele;
			bst.del_ele(ele, curr);
			break;
		}
		case '3':
		{
			res = bst.findmax(curr);
			cout << "max element in the tree - "<<res << endl;
			break;
		}
		case '4':
		{
			res = bst.findmin(curr);
			cout << "min element in the tree - " << res << endl;
			break;
		}
		case '5':
		{
			res = bst.height(curr);
		}
		}
		cout << "do you want to continue?y/n" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return 0;
}