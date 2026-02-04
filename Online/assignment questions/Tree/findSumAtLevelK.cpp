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

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	int data;
	int size;
	node** child;

	node(int d,int s)
	{
		data=d;
		size=s;
		child=new node*[s];
	}
};

node* buildTree()
{
	int d,s;
	cin>>d>>s;
	node* root=new node(d,s);
	for(int i=0;i<s;i++)
	{
		root->child[i]=buildTree();
	}
	return root;
}

int sumAtLevelK(node* root,int k)
{
	int level=0;
	queue<node*> q;
	int sum=0;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* curr=q.front();
		q.pop();
		if(curr==NULL)
		{
			level++;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			if(level==k)
			{
				sum+=curr->data;
			}
			if(level>k)
			{
				break;
			}

			for(int i=0;i<curr->size;i++)
			{
				q.push(curr->child[i]);
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	node* root=buildTree();
	int k;
	cin>>k;
	cout<<sumAtLevelK(root,k)<<endl;
	return 0;
}