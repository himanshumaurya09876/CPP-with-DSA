// IS BALANCED (BINARY TREE)
// Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.

// Input Format:
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints:
// None

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true

#include <iostream>
#include <cstdlib>
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
	node* root=NULL;
	string choice;
	cin>>choice;
	if(choice=="true")
	{
		int d;
		cin>>d;
		root=new node(d);
		root->left=buildTree();
		root->right=buildTree();
	}
	return root;
}

bool isBalanced(node* root,int &h)
{
	if(root==NULL)
	{
		h=0;
		return true;
	}

	int lh=0,rh=0;
	if(isBalanced(root->left,lh) && isBalanced(root->right,rh) && abs(lh-rh)<=1)
	{
		h=max(lh,rh)+1;
		return true;
	}
	h=max(lh,rh)+1;
	return false;
}

int main(int argc, char const *argv[])
{
	int d;
	cin>>d;
	node* root=new node(d);
	root->left=buildTree();
	root->right=buildTree();
	int num;
	if(isBalanced(root,num))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}