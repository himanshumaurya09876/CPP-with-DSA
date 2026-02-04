//binary tree is a generic tree in which max number of childs that a node can have is two
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

node* buildTreeFromArray(int arr[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}

	int mid=(s+e)/2;
	node* root=new node(arr[mid]);
	root->left=buildTreeFromArray(arr,s,mid-1);
	root->right=buildTreeFromArray(arr,mid+1,e);
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

void printInOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}

void printPostOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

void printBFS(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* curr=q.front();
		q.pop();
		if(curr==NULL)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<curr->data<<" ";
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
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	node*root=buildTreeFromArray(arr,0,n-1);
	printInOrder(root);
	cout<<endl;
	printPostOrder(root);
	cout<<endl;
	printPreOrder(root);
	cout<<endl;
	printBFS(root);
	return 0;
}