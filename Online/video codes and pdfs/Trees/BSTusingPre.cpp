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

node* formBSTfromPre(int pre[],int n)
{
	int in[100];
	for(int i=0;i<n;i++)
	{
		in[i]=pre[i];
	}
	sort(in,in+n);
	node* root=buildTreeFromInAndPre(in,pre,0,n-1);
	return root;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int pre[100];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	node* root=formBSTfromPre(pre,n);
	printBFS(root);
	return 0;
}