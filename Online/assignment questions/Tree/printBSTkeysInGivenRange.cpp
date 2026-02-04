// PRINT BST KEYS IN THE GIVEN RANGE
// You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

// Input Format:
// First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

// Constraints:
// 1 < t < 20 1 < n < 50

// Output Format
// For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive).

// Sample Input
// 1
// 5
// 4 3 2 5 6
// 3 5
// Sample Output
// # Preorder : 4 3 2 5 6 
// # Nodes within range are : 3 4 5 

#include <iostream>
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

node* insert(node* root,int d)
{
	if(root==NULL)
	{
		root=new node(d);
		return root;
	}

	if(root->data < d)
	{
		root->right=insert(root->right,d);
	}
	else
	{
		root->left=insert(root->left,d);
	}
	return root;
}

node* buildBSTFromArray(int arr[],int n)
{
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		root=insert(root,arr[i]);
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
	preorder(root->left);
	preorder(root->right);
}

void printInRange(node* root,int key1,int key2)
{
	if(root==NULL)
	{
		return;
	}
	printInRange(root->left,key1,key2);
	if(key1<=root->data && key2>=root->data)
	{
		cout<<root->data<<" ";
	}
	printInRange(root->right,key1,key2);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,arr[50];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int key1,key2;
		cin>>key1>>key2;
		node* root=buildBSTFromArray(arr,n);
		cout<<"# Preorder : ";
		preorder(root);
		cout<<endl;
		cout<<"# Nodes within range are : ";
		printInRange(root,key1,key2);
		cout<<endl;
		t--;
	}
	return 0;
}