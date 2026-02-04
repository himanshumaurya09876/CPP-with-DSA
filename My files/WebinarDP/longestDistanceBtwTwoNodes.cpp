//longest diameter in a tree
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* leftChild;
	node* rightChild;

	node(int d)
	{
		data=d;
		leftChild=NULL;
		rightChild=NULL;
	}
};

node* buildTree()
{
	int data;
	cin>>data;
	if(data==-1)
	{
		return NULL;
	}

	node* newnode=new node(data);
	newnode->leftChild=buildTree();
	newnode->rightChild=buildTree();
	return newnode;
}

int height(node* root)
{
	if(root==NULL)
	{
		return -1;
	}

	int lh=height(root->leftChild);
	int rh=height(root->rightChild);

	int h=max(lh,rh)+1;
	return h;
}

int longestDia(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int currdia=height(root->leftChild)+height(root->rightChild)+2;
	int leftdia=longestDia(root->leftChild);
	int rightdia=longestDia(root->rightChild);

	return max(currdia,max(leftdia,rightdia));
}

int longestDiaOpt(node* root,int *h)//it is lso DP
{
	if(root==NULL)
	{
		*h=-1;
		return 0;
	}

	int lh=0,rh=0;

	int leftd=longestDiaOpt(root->leftChild,&lh);
	int rightd=longestDiaOpt(root->rightChild,&rh);
	int currd=lh+rh+2;
	*h=max(lh,rh)+1;

	return max(currd,max(leftd,rightd)); 
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=buildTree();
	cout<<longestDia(root)<<" "<<height(root)<<endl;
	int num;
	cout<<longestDiaOpt(root,&num)<<" "<<num<<endl;
	return 0;
}

//2 1 4 -1 -1 5 6 -1 -1 7 -1 -1 7 5 6 1 -1 -1 -1 4 -1 -1 42 -1 -1
//2 1 4 -1 -1 5 6 -1 -1 7 -1 -1 7 5 6 1 -1 -1 -1 4 -1 -1 42 -1 8 -1 9 -1 11 -1 10 -1 -1