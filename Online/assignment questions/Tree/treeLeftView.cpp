// TREE LEFT VIEW
// Given a binary tree , print its nodes from root to bottom as visible from left side of tree

// Input Format:
// Level order input for the binary tree will be given.

// Constraints:
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the left view of the tree

// Sample Input
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// Sample Output
// 1 2 4

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

void buildTreeFromLevelOrderHelper(queue<node*> &q)
{
	if(q.size()<=1)
	{
		return;
	}

	while(!q.empty() && q.front()!=NULL)
	{
		node* entry=q.front();
		q.pop();
		int l,r;
		cin>>l>>r;
		if(l==-1)
		{
			entry->left=NULL;
		}
		else
		{
			entry->left=new node(l);
			q.push(entry->left);
		}

		if(r==-1)
		{
			entry->right=NULL;
		}
		else
		{
			entry->right=new node(r);
			q.push(entry->right);
		}
	}
	q.pop();
	q.push(NULL);
	buildTreeFromLevelOrderHelper(q);
}

node* buildTreeFromLevelOrder()
{
	queue<node*> q;
	node* root=NULL;
	int d;
	cin>>d;
	if(d!=-1)
	{
		root=new node(d);
		q.push(root);
	}
	q.push(NULL);
	buildTreeFromLevelOrderHelper(q);
	return root;
}

void printLeftViewOfTree(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	cout<<root->data<<" "; 
	while(!q.empty())
	{
		node* entry=q.front();
		q.pop();
		if(entry==NULL)
		{
			if(!q.empty())
			{
				cout<<q.front()->data<<" ";
				q.push(NULL);
			}
		}
		else
		{
			if(entry->left!=NULL)
			{
				q.push(entry->left);
			}

			if(entry->right!=NULL)
			{
				q.push(entry->right);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	node* root=buildTreeFromLevelOrder();
	printLeftViewOfTree(root);
	return 0;
}