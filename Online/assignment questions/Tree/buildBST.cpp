// BUILD BST
// You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

// Input Format:
// First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers.

// Constraints:
// 1 < t < 100 1< n < 1000

// Output Format
// Print the preorder of the tree.

// Sample Input
// 1
// 7
// 1 2 3 4 5 6 7
// Sample Output
// 4 2 1 3 6 5 7


#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* lc;
	node* rc;

	node(int d)
	{
		data=d;
		lc=NULL;
		rc=NULL;
	}
};

node* insert(node* root,int d)
{
	if(root==NULL)
	{
		root=new node(d);
		return root;
	}
	if(root->data>=d)
	{
		root->lc=insert(root->lc,d);
	}
	else
	{
		root->rc=insert(root->rc,d);
	}
	return root;
}

void preorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->lc);
	preorder(root->rc);
}

node* buildBST(int n)
{
	int data;
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		root=insert(root,data);
	}
	return root;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		node* root=buildBST(n);
		preorder(root);
		cout<<endl;
		t--;
	}
	return 0;
}