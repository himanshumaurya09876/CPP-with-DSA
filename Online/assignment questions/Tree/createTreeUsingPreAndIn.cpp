// CREATE TREE ( USING PREORDER AND INORDER)
// Given preorder and inorder create the tree

// Input Format:
// Enter the size of the preorder array N then add N more elements and store in the array, then enter the size of the inorder array M and add M more elements and store in the array

// Constraints:
// None

// Output Format
// Display the tree using the display function

// Sample Input
// 3
// 1
// 2
// 3
// 3
// 3
// 2
// 1
// Sample Output
// 2 => 1 <= END
// 3 => 2 <= END
// END => 3 <= END

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

void printPreOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	if(root->left!=NULL)
	{
		cout<<root->left->data<<" => ";
	}
	else
	{
		cout<<"NULL => ";
	}
	cout<<root->data<<" ";
	if(root->right!=NULL)
	{
		cout<<" <= "<<root->right->data;
	}
	else
	{
		cout<<" <= NULL";
	}
	cout<<endl;
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main(int argc, char const *argv[])
{
	int n,m,pre[100],in[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>in[i];
	}
	node* root=buildTreeFromInAndPre(in,pre,0,n-1);
	printPreOrder(root);
	return 0;
} 