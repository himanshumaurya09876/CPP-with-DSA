// TREE RIGHT VIEW
// Given a binary tree , print its nodes from root to bottom as visible from right side of tree

// Input Format:
// Level order input for the binary tree will be given.

// Constraints:
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the right view of the tree

// Sample Input
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// Sample Output
// 1 3 6

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

void printRightViewOfTree(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* entry1=q.front(),*entry2=NULL;
		q.pop();
		if(!q.empty())
		{
			entry2=q.front();
		}
		if(entry1==NULL)
		{
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			if(entry2==NULL)
			{
				cout<<entry1->data<<" ";
			}

			if(entry1->left!=NULL)
			{
				q.push(entry1->left);
			}

			if(entry1->right!=NULL)
			{
				q.push(entry1->right);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	node* root=buildTreeFromLevelOrder();
	printRightViewOfTree(root);
	return 0;
}