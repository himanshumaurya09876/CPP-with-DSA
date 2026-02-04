// STRUCTURALLY IDENTICAL (BINARY TREE)
// Given two trees check if they are structurally identically

// Input Format:
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints:
// None

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true

#include <iostream>
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

bool isStructIdentical(node* root1,node* root2)
{
	if(root1!=NULL && root2!=NULL && isStructIdentical(root1->left,root2->left) && isStructIdentical(root1->right,root2->right))
	{
		return true;
	}		
	else if(root1==NULL && root2==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int d;
    cin>>d;
    node* root1=new node(d);
    root1->left=buildTree();
    root1->right=buildTree();
	cin>>d;
    node* root2=new node(d);
    root2->left=buildTree();
    root2->right=buildTree();
	if(isStructIdentical(root1,root2))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}