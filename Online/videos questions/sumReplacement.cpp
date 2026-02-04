#include <iostream>
#include <map>
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

node* buildTree()
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}

	node* root=new node(d);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}

void preOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void levelOrderMain(node* root,map<int,vector<pair<int,node*> > >& mp,int l=0,int c=0)
{
	if(root==NULL)
	{
		return;
	}

	mp[l].push_back(make_pair(c,root));
	levelOrderMain(root->left,mp,l+1,c-1);
	levelOrderMain(root->right,mp,l+1,c+1);
}

void levelOrder(node* root)
{
	map<int,vector<pair<int,node*> > > mp;
	levelOrderMain(root,mp,0,0);
	for(auto it:mp)
	{
		sort((it.second).begin(),(it.second).end());
		for(auto itr:it.second)
		{
			cout<<(itr.second)->data<<" ";
		}
		cout<<endl;
	}
}

int replaceBySumOfChild(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL)
	{
		return root->data;
	}

	int currData=root->data;
	root->data=replaceBySumOfChild(root->left)+replaceBySumOfChild(root->right);
	return currData+root->data;
}

int main(int argc, char const *argv[])
{
	node* root=buildTree();
	replaceBySumOfChild(root);
	preOrder(root);
	cout<<endl;
	levelOrder(root);
	return 0;
}

//input
//1 2 3 -1 -1 4 -1 -1 5 6 7 -1 -1 8 -1 -1 9 -1 -1 
//1 3 4 2 7 -1 -1 8 -1 -1 6 9 -1 -1 10 -1 -1 5 -1 11 -1 12 13 -1 -1 14 15 -1 -1 16 -1 -1 -1