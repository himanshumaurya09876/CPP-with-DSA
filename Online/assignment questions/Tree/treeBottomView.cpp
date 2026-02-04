// TREE BOTTOM VIEW
// Given a binary tree , print the nodes in left to right manner as visible from below the tree

// Input Format:
// Level order input for the binary tree will be given.

// Constraints:
// No of nodes in the tree can be less than or equal to 10^7

// Output Format
// A single line containing space separated integers representing the bottom view of the tree

// Sample Input
// 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
// Sample Output
// 4 2 6 3


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

int height(node* root)
{
	if(root==NULL)
	{
		return -1;
	}

	return max(height(root->left),height(root->right))+1;
}

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

void bottomView(node* root)
{
	map<int,vector<pair<int,node*> > > mp;
	verticalOrderMain(root,mp,0,0);
	for(auto it:mp)
	{
		sort((it.second).begin(),(it.second).end());
		cout<<((it.second)[(it.second).size()-1]).second->data<<" ";
	}
}


// this is not perfect
// void printBottomViewOfTree(node* root)
// {
// 	int h=height(root);
// 	queue<node*> q;
// 	q.push(root);
// 	q.push(NULL);
// 	while(!q.empty())
// 	{
// 		if(h==1)
// 		{
// 			break;
// 		}

// 		node* curr=q.front();
// 		q.pop();
// 		if(curr==NULL)
// 		{
// 			h--;
// 			if(!q.empty())
// 				q.push(NULL);
// 		}
// 		else
// 		{
// 			if(curr->left!=NULL)
// 			{
// 				q.push(curr->left);
// 			}
// 			if(curr->right!=NULL)
// 			{
// 				q.push(curr->right);
// 			}
// 		}
// 	}

// 	while(!q.empty() && q.front()!=NULL)
// 	{
// 		node* curr=q.front();
// 		q.pop();
// 		if(curr->left!=NULL)
// 		{
// 			cout<<curr->left->data<<" ";
// 		}

// 		cout<<curr->data<<" ";

// 		if(curr->right!=NULL)
//         {
//             if(q.front()!=NULL)
//             {
//                 if(q.front()->left==NULL)
//                 {
//                     cout<<curr->right->data<<" ";
//                 }
//             }
//             else
//             {
//                 cout<<curr->right->data<<" ";
//             }
//         }
// 	}
// }

int main(int argc, char const *argv[])
{
	node* root=buildTreeFromLevelOrder();
	bottomView(root);
	return 0;
}