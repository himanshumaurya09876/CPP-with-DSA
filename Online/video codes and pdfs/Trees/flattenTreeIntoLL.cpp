#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* lc;
	node* rc;

	node(int d)
	{
		data=d;
		lc=NULL;
		rc=NULL;
	}
};

node* insert(node* root,int d)
{
	if(root==NULL)
	{
		root=new node(d);
		return root;
	}
	if(root->data>=d)
	{
		root->lc=insert(root->lc,d);
	}
	else
	{
		root->rc=insert(root->rc,d);
	}
	return root;
}

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->lc);
	cout<<root->data<<" ";
	inorder(root->rc);
}

node* buildBST(int n)
{
	int data;
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		root=insert(root,data);
	}
	return root;
}

pair<node* , node*> flatten(node* root)
{
	pair<node*, node*> p;
	if(root==NULL)
	{
		p.first=p.second=NULL;
		return p;
	}

	if(root->lc==NULL && root->rc==NULL)
	{
		p.first=p.second=root;
	}
	else if(root->lc!=NULL && root->rc==NULL)
	{
		pair<node*, node*> leftLL=flatten(root->lc);
		(leftLL.second)->rc=root;
		p.first=leftLL.first;
		p.second=root;
	}
	else if(root->lc==NULL && root->rc!=NULL)
	{
		pair<node*, node*> rightLL=flatten(root->rc);
		root->rc=rightLL.first;
		p.first=root;
		p.second=rightLL.second;
	}
	else
	{
		pair<node*, node*> rightLL=flatten(root->rc);
		pair<node*, node*> leftLL=flatten(root->lc);
		(leftLL.second)->rc=root;
		root->rc=rightLL.first;
		p.first=leftLL.first;
		p.second=rightLL.second;
	}
	return p;
}

int main() {
	int n;
	cin>>n;
	node* root=buildBST(n);
	inorder(root);
	cout<<endl;
	pair<node*, node*> LL=flatten(root);
	node* temp=LL.first;
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->rc;
	}
	cout<<"NULL"<<endl;
	return 0;
}