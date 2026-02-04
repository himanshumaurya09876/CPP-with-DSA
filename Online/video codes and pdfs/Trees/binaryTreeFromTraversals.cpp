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

int main(int argc, char const *argv[])
{
	int pre[]={4,1,25,9,10,20,2,30};
	int in[]={25,1,10,9,20,4,2,30};
	int post[]={25,10,20,9,1,30,2,4};
	int n=sizeof(in)/sizeof(in[0]);
	cout<<"Tree using in and pre order traversal: "<<endl;
	node* root1=buildTreeFromInAndPre(in,pre,0,n-1);
	printBFS(root1);
	cout<<"Tree using in and post order traversal: "<<endl;
	node* root2=buildTreeFromInAndPost(in,post,0,n-1);
	printBFS(root2);
	return 0;
}