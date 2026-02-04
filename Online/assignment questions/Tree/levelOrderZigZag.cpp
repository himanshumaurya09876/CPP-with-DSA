// LEVEL ORDER ( ZIGZAG , BINARY TREE)
// Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left. Each level should be printed at a new line.

// Input Format:
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints:
// None

// Output Format
// Display the values in zigzag level order in which each value is separated by a space

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// 10 30 20 40 50 60 73 

#include <iostream>
#include <stack>
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

node* buildTree()
{
	node* root=NULL;
	string choice;
	cin>>choice;
	if(choice=="true")
	{
		int d;
		cin>>d;
		root=new node(d);
		root->left=buildTree();
		root->right=buildTree();
	}
	return root;
}

void levelOrderZigZag(node* root)
{
	int level=1;
	queue<node*> q;
	stack<int> st;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* curr=q.front();
		q.pop();
		if(curr==NULL)
		{
			level++;
			if(level%2)
			{
				while(!st.empty())
				{
					cout<<st.top()<<" ";
					st.pop();
				}
			}
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			if(level%2)
			{
				cout<<curr->data<<" ";
			}
			else
			{
				st.push(curr->data);
			}
			if(curr->left!=NULL)
			{
				q.push(curr->left);
			}
			if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int d;
    cin>>d;
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
	levelOrderZigZag(root);
	return 0;
}