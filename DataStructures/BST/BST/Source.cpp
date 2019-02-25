#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
class __BST__
{
	struct node *start;
public:
	__BST__();
	node *insert(int, node *);
	void del_ele(int);
	void inorder(node *);
	void preorder();
	void postorder();
	int findmax(node *);
	int findmin(node *);
	int height(node *);
	int noofleafnodes(node *);
	int noofnonleafnodes(node *);
	~__BST__();
};
__BST__::__BST__()
{
	start = NULL;
}
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
		if (ele < curr->data)
			curr->left = insert(ele, curr->left);
		else
			curr->right = insert(ele, curr->right);
		return curr;
	}
}
int __BST__::findmax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
		{
			curr = curr->right;
		}
		return (curr->data);
	}
	return -1;
}
int __BST__::findmin(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return (curr->data);
	}
	return -1;
}
int __BST__::noofleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return (noofleafnodes(curr->left) + noofleafnodes(curr->right));
}
int __BST__::noofnonleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return (noofleafnodes(curr->left) + noofleafnodes(curr->right)+1);
}
void __BST__::inorder(struct node *curr)
{

}