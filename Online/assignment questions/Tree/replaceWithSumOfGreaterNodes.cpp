// REPLACE WITH SUM OF GREATER NODES
// Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.

// Input Format:
// The first line contains a number n showing the length of the inorder array of BST The next n line contains an integer denoting the elements of the array

// Constraints:
// 2 ≤ N ≤ 10^3

// Output Format
// Print the preorder traversal of the new bst

// Sample Input
// 7
// 20 30 40 50 60 70 80
// Sample Output
// 260 330 350 300 150 210 80


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

int replaceBySum(node* root,int num=0)
{
	if(root==NULL)
	{
		return 0;
	}
	
    if(root->right==NULL)
    {
        root->data+=num;
    }
    else
    {
        root->data+=replaceBySum(root->right,num);
    }
	num=replaceBySum(root->left,root->data);
    if(root->left==NULL)
    {
        return root->data;
    }
    return num;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	node* root=buildBSTfromArray(arr,0,n-1);
	replaceBySum(root);
	printPreOrder(root);
	cout<<endl;
	return 0;
}