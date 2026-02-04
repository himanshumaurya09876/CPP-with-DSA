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

#include <iostream>
#include <algorithm>
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

node* buildBSTfromArray(int arr[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node* root=new node(arr[mid]);
	root->left=buildBSTfromArray(arr,s,mid-1);
	root->right=buildBSTfromArray(arr,mid+1,e);
	return root;
}

void printPreOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int arr[1000];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		node* root=buildBSTfromArray(arr,0,n-1);
		printPreOrder(root);
		cout<<endl;
		t--;
	}
	return 0;
}