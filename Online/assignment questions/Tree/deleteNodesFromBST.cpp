// DELETE NODES FROM BST
// You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree.

// Input Format:
// First line contains integer t as number of test cases. Each test case It contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers.

// Constraints:
// 1 < t < 100 1< n,m < 1000

// Output Format
// Print the preorder of the tree

// Sample Input
// 1
// 7
// 5 3 2 4 7 6 8
// 3
// 2 3 5
// Sample Output
// 4 7 6 8

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

// void insert(node*& root,int d)
// {
// 	if(root==NULL)
// 	{
// 		root=new node(d);
// 		return;
// 	}

// 	if(root->data < d)
// 	{
// 		insert(root->right,d);
// 	}
// 	else
// 	{
// 		insert(root->left,d);
// 	}
// }

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

node* deleteInBST(node* root,int d)
{
	if(root==NULL)
	{
		return NULL;
	}

	if(root->data < d)
	{
		root->right=deleteInBST(root->right,d);
	}
	else if(root->data > d)
	{
		root->left=deleteInBST(root->left,d);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		} 
		else if(root->left!=NULL && root->right==NULL)
		{
			node* temp=root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			node* temp=root->right;
			delete root;
			return temp;
		}
		else
		{
			node* temp=root->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			root->data=temp->data;
			root->left=deleteInBST(root->left,root->data);
		}
	}
	return root;
}

node* deleteInBSTarray(node* root,int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		root=deleteInBST(root,arr[i]);
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

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,m,arr1[1000],arr2[1000];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr1[i];
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>arr2[i];
		}
		node* root=buildBSTFromArray(arr1,n);
		root=deleteInBSTarray(root,arr2,m);
		preorder(root);
		cout<<endl;
		t--;
	}
	return 0;
}