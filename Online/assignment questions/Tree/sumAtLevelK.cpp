// FIND SUM AT LEVEL K
// Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

// Input Format:
// Tree Input and an integer K

// Constraints:
// 1<K<10

// Output Format
// A single line containing the sum

// Sample Input
// 1 2
// 2 2
// 3 0
// 4 0
// 5 2
// 6 0
// 7 0
// 2
// Sample Output
// 20

#include<iostream>
#include<queue>
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

node* buildTree(node* root)
{
	int data;
	int noC;
	cin>>data>>noC;
	root=new node(data);
	if(noC==1)
	{
		root->lc=buildTree(root->lc);
	}
	else if(noC==2)
	{
		root->lc=buildTree(root->lc);
		root->rc=buildTree(root->rc);
	}
	return root;
}

int sumAtLevelK(node* root,int k)
{
	queue<node*> q;
	int i=0;
	int sum=0;
	q.push(root);
	q.push(NULL);
	while(q.size()>1)
	{
		if(q.front()==NULL)
		{
			i++;
			q.push(NULL);
			q.pop();
		}
		else
		{
			node* temp=q.front();
			if(temp->lc!=NULL)
			{
				q.push(temp->lc);
			}
			if(temp->rc!=NULL)
			{
				q.push(temp->rc);
			}
			if(i==k)
			{
				sum+=temp->data;
			}
			q.pop();
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	int k;
	root=buildTree(root);
	cin>>k;
	cout<<sumAtLevelK(root,k)<<endl;
	return 0;
}