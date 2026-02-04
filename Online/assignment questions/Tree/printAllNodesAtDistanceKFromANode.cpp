// PRINT ALL NODES AT DISTANCE K FROM A GIVEN NODE
// Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. Print 0 if no such node exist at distance k.

// Input Format:
// The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT. The next line will contain an integer T. Then T lines follow you will be given 2 integers the first one denoting the value of Node and the second one denoting the value of k.

// Constraints:
// 2 ≤ N ≤ 10^3

// Output Format
// On T lines print space separated desired output for each test case in sorted form

// Sample Input
// 4
// 60 65 50 70
// 50 65 60 70
// 2
// 60 1
// 65 2
// Sample Output
// 65 70
// 70

#include <iostream>
#include <vector>
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

void printChildNodesAtK(node* root,int k,vector<int> &v)
{
	if(root==NULL || k<0)
	{
		return;
	}

	if(k==0)
	{
		v.push_back(root->data);
		return;
	}

	printChildNodesAtK(root->left,k-1,v);
	printChildNodesAtK(root->right,k-1,v);
}

int printNodesAtK(node* root,int data,int k,vector<int> &v,int d=0)
{
	if(root==NULL)
	{
		return -1;
	}

	if(root->data==data)
	{
		printChildNodesAtK(root,k,v);
		return d;
	}

	int dl=printNodesAtK(root->left,data,k,v,d+1);
	if(dl!=-1)
	{
		if(dl-d==k)
		{
			v.push_back(root->data);
		}
		else
		{
			printChildNodesAtK(root->right,k-dl+d-1,v);
		}
		return dl;
	}

	int dr=printNodesAtK(root->right,data,k,v,d+1);
	if(dr!=-1)
	{
		if(dr-d==k)
		{
			v.push_back(root->data);
		}
		else
		{
			printChildNodesAtK(root->left,k-dr+d-1,v);
		}
		return dr;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *pre=new int[n];
	int *in=new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node* root=buildTreeFromInAndPre(in,pre,0,n-1);
	int t;
	cin>>t;
	while(t>0)
	{
		int data,k;
		vector<int> v;
		cin>>data>>k;
		printNodesAtK(root,data,k,v);
		sort(v.begin(),v.end());
		for(auto it:v)
		{
			cout<<it<<" ";
		}
		if(v.size()==0)
		{
			cout<<0;
		}
		cout<<endl;
		t--;
	}
	return 0;
}