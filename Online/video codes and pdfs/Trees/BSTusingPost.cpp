#include <iostream>
#include <queue>
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

node* buildTreeFromInAndPost(int in[],int post[],int s,int e)
{
	static int i=e;//or global will also work
	if(s>e)
	{
		return NULL;
	}
	int j;
	node* root=new node(post[i]);
	for(j=s;j<=e;j++)
	{
		if(in[j]==post[i])
		{
			break;
		}
	}
	i--;
	root->right=buildTreeFromInAndPost(in,post,j+1,e);
	root->left=buildTreeFromInAndPost(in,post,s,j-1);
	return root;
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

node* formBSTfromPost(int post[],int n)
{
	int in[100];
	for(int i=0;i<n;i++)
	{
		in[i]=post[i];
	}
	sort(in,in+n);
	node* root=buildTreeFromInAndPost(in,post,0,n-1);
	return root;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int post[100];
	for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
	node* root=formBSTfromPost(post,n);
	printBFS(root);
	return 0;
}