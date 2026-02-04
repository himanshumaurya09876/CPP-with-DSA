// TREE TOP VIEW
// Given a binary tree , print the nodes in left to right manner as visible from above the tree

// Input Format:
// Level order input for the binary tree will be given.

// Constraints:
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the top view of the tree

// Sample Input
// 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
// Sample Output
// 4 2 1 3

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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

void buildTreeFromLevelOrderHelper(queue<node*> &q)
{
	if(q.size()<=1)
	{
		return;
	}

	while(!q.empty() && q.front()!=NULL)
	{
		node* entry=q.front();
		q.pop();
		int l,r;
		cin>>l>>r;
		if(l==-1)
		{
			entry->left=NULL;
		}
		else
		{
			entry->left=new node(l);
			q.push(entry->left);
		}

		if(r==-1)
		{
			entry->right=NULL;
		}
		else
		{
			entry->right=new node(r);
			q.push(entry->right);
		}
	}
	q.pop();
	q.push(NULL);
	buildTreeFromLevelOrderHelper(q);
}

node* buildTreeFromLevelOrder()
{
	queue<node*> q;
	node* root=NULL;
	int d;
	cin>>d;
	if(d!=-1)
	{
		root=new node(d);
		q.push(root);
	}
	q.push(NULL); 
	buildTreeFromLevelOrderHelper(q);
	return root;
}



// // this function is not considering all types of tree only full or perfect tree is considered here
// void printTopViewOfTree1(node* root)
// {
// 	queue<node*> q;
// 	queue<int> rv;
// 	stack<int> lv;
// 	q.push(root);
// 	q.push(NULL);
// 	while(!q.empty())
// 	{
// 		node *entry1=q.front(),*entry2=NULL;
// 		q.pop();
// 		if(!q.empty())
// 		{
// 			entry2=q.front();
// 		}
// 		if(entry1==NULL)
// 		{
// 			if(!q.empty())
// 			{
// 				lv.push(q.front()->data);
// 				q.push(NULL);
// 			}
// 		}
// 		else
// 		{
// 			if(entry2==NULL)
// 			{
// 				rv.push(entry1->data);
// 			}

// 			if(entry1->left!=NULL)
// 			{
// 				q.push(entry1->left);
// 			}

// 			if(entry1->right!=NULL)
// 			{
// 				q.push(entry1->right);
// 			}
// 		}
// 	}

// 	while(!lv.empty())
// 	{
// 		cout<<lv.top()<<" ";
// 		lv.pop();
// 	}

// 	while(!rv.empty())
// 	{
// 		cout<<rv.front()<<" ";
// 		rv.pop();
// 	}
// }



// //this function is also not general
// void printLeftChilds(node* root)
// {
// 	if(root==NULL)
// 	{
// 		return;
// 	}

// 	printLeftChilds(root->left);
// 	cout<<root->data<<" ";
// }

// void printRightChilds(node* root)
// {
// 	if(root==NULL)
// 	{
// 		return;
// 	}

// 	cout<<root->data<<" ";
// 	printRightChilds(root->right);
// }

// void printTopViewOfTree(node* root)
// {
// 	printLeftChilds(root);
// 	printRightChilds(root->right);
// }


void verticalOrderMain(node* root,map<int,vector<pair<int,node*> > >& mp,int l=0,int c=0)
{
	if(root==NULL)
	{
		return;
	}

	mp[c].push_back(make_pair(l,root));
	verticalOrderMain(root->left,mp,l+1,c-1);
	verticalOrderMain(root->right,mp,l+1,c+1);
} 

void topView(node* root)
{
	map<int,vector<pair<int,node*> > > mp;
	verticalOrderMain(root,mp,0,0);
	for(auto it:mp)
	{
		sort((it.second).begin(),(it.second).end());
		cout<<(((it.second)[0]).second)->data<<" ";
	}
}

int main(int argc, char const *argv[])
{
	node* root=buildTreeFromLevelOrder();
	topView(root);
	return 0;
}