// LARGEST BST IN A BINARY TREE
// Given a Binary Tree, write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)

// Input Format:
// The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT.

// Constraints:
// 2 ≤ N ≤ 10^3

// Output Format
// A single integer denoting the largest bst in a bt.

// Sample Input
// 4
// 60 65 50 70
// 50 65 60 70
// Sample Output
// 2

#include <bits/stdc++.h>
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

node* buildTreeFromInAndPre(int in[],int pre[],int s,int e)
{
	static int i=0;//or global will also work
	if(s>e)
	{
		return NULL;
	}
	int j;
	node* root=new node(pre[i]);
	for(j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			break;
		}
	}
	i++;
	root->left=buildTreeFromInAndPre(in,pre,s,j-1);
	root->right=buildTreeFromInAndPre(in,pre,j+1,e);
	return root;
}

class nodeData
{
public:
	bool isBST;
	int minm;
	int maxm;
	int maxBSTsize;

	nodeData()
	{
		isBST=true;
		minm=INT_MAX;
		maxm=INT_MIN;
		maxBSTsize=0;
	}
};

nodeData largestBSTinBT(node* root)
{
	if(root==NULL)
	{
		return nodeData();
	}

	nodeData curr;
	nodeData left=largestBSTinBT(root->left);
	nodeData right=largestBSTinBT(root->right);
	if(left.isBST && right.isBST && left.maxm<=root->data && right.minm>root->data)
	{
		curr.isBST=true;
		curr.maxBSTsize=left.maxBSTsize+right.maxBSTsize+1;
	}
	else
	{
		curr.isBST=false;
		curr.maxBSTsize=max(left.maxBSTsize,right.maxBSTsize);
	}
	curr.minm=min(left.minm,root->data);
	curr.maxm=max(right.maxm,root->data);
	return curr;
}

int main(int argc, char const *argv[])
{
	int n,pre[1000],in[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node* root=buildTreeFromInAndPre(in,pre,0,n-1);
	cout<<largestBSTinBT(root).maxBSTsize<<endl;
	return 0;
}