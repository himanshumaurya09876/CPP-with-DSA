// VERTICAL ORDER PRINT BINARY TREE
// You will be given a Binary Tree. Your task is to print the binary tree in Vertical Fashion. The image below describes how we define a vertical traversal of a tree.

// Input Format:
// You will be given an Integer N denoting the number of levels in the corresponding tree. On the next line you will be given (2^N)-1 integers denoting the level order input for the tree. If at any level any node is absent then that will denoted by -1 and every integer other than -1 shows the presence of a node at that level.

// Constraints:
// Output Format
// Print all nodes of a given column in the same line.

// Image

// Sample Input
// 4 
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
// Sample Output
// 4
// 2
// 1 5 6
// 3 8 
// 7
// 9

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class node
{
public:
	int data;
	node* lc;
	node* rc;

	node(int data)
	{
		this->data=data;
		lc=NULL;
		rc=NULL;
	}
};

void helper(queue<node*> &q)
{
	if(q.empty() || q.front()==NULL)
	{
		return;
	}

	while(q.front()!=NULL)
	{
		node* entry=q.front();
		q.pop();
		int d;
		cin>>d;
		if(d!=-1)
		{
			entry->lc=new node(d);
			q.push(entry->lc);
		}
		cin>>d;
		if(d!=-1)
		{
			entry->rc=new node(d);
			q.push(entry->rc);
		}
	}
	q.pop();
	q.push(NULL);
	helper(q);
}

node* makeTreeUsingLevelOrderTraversal()
{
	int d;
	cin>>d;
	node* root=new node(d);
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	helper(q);
	return root;
}

void helper1(node* root,map<int,vector<pair<int,node*> > > &hash,int h=0,int v=0)
{
	if(root==NULL)
	{
		return;
	}

	hash[v].push_back(make_pair(h,root));
	helper1(root->lc,hash,h+1,v-1);
	helper1(root->rc,hash,h+1,v+1);
}

void printVerticalOrder(node* root)
{
	map<int,vector<pair<int,node*> > > hash;
	helper1(root,hash);
	for(auto it:hash)
	{
		sort(it.second.begin(),it.second.end());
		for(auto itr:it.second)
		{
			cout<<itr.second->data<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int l;
	cin>>l;
	node* root=makeTreeUsingLevelOrderTraversal();
	printVerticalOrder(root);
	return 0;
}