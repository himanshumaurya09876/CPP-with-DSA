#include <bits/stdc++.h>
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

int findHeight(node*root)
{
	if(root==NULL)
	{
		return -1;
	}

	int leftHeight=findHeight(root->leftChild);
	int rightHeight=findHeight(root->rightChild);
	int rootHeight=max(leftHeight,rightHeight)+1;
	return rootHeight;
}

int findTotalNodes(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftTreeNodes=findTotalNodes(root->leftChild);
	int rightTreeNodes=findTotalNodes(root->rightChild);
	int currTreeNodes=leftTreeNodes+rightTreeNodes+1;
	return currTreeNodes;
}

int sumOfAllNodes(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftTreeSum=sumOfAllNodes(root->leftChild);
	int rightTreeSum=sumOfAllNodes(root->rightChild);
	int currTreeSum=leftTreeSum+rightTreeSum+root->data;
	return currTreeSum;
}

void preorderPrint(node*root)//preorder traversal
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorderPrint(root->leftChild);
	preorderPrint(root->rightChild);
}

void inorderPrint(node*root)//inorder traversal
{
	if(root==NULL)
	{
		return;
	}
	inorderPrint(root->leftChild);
	cout<<root->data<<" ";
	inorderPrint(root->rightChild);
}

void postorderPrint(node*root)//postorder traversal
{
	if(root==NULL)
	{
		return;
	}
	postorderPrint(root->leftChild);
	postorderPrint(root->rightChild);
	cout<<root->data<<" ";
}

void printLevelK(node*root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
	}
	printLevelK(root->leftChild,k-1);
	printLevelK(root->rightChild,k-1);
}

//O(n*n) worst case
//O(nlog(n)) best case
void levelOrderPrint(node*root)//level order traversal
{
	int h=findHeight(root);
	for(int i=0;i<=h;i++)
	{
		printLevelK(root,i);
		cout<<endl;
	}
}

//O(n) optimized
void levelOrderPrintOptimized(node*root)//level order traversal
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1)
	{
		//cout<<q.size()<<endl;
		node* first=q.front();
		q.pop();
		if(first==NULL)
		{
			cout<<endl;
			q.push(NULL);
		}
		else
		{
			cout<<first->data<<" ";
			if(first->leftChild!=NULL)
				q.push(first->leftChild);
			if(first->rightChild!=NULL)
				q.push(first->rightChild);
		}
	}
}

//O(n*n)
int diameter(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int currDiameter=findHeight(root->leftChild)+findHeight(root->rightChild)+2;
	int leftDiameter=diameter(root->leftChild);
	int rightDiameter=diameter(root->rightChild);

	return max(currDiameter,max(leftDiameter,rightDiameter));
}

//O(n)
int diameterOptimized(node*root,int *h)
{
	int lh=0,rh=0;
	if(root==NULL)
	{
		*h=-1;
		return -1;
	}

	int leftDiameter=diameterOptimized(root->leftChild,&lh);
	int rightDiameter=diameterOptimized(root->rightChild,&rh);
	*h=max(lh,rh)+1;
	return max(lh+rh+2,max(leftDiameter,rightDiameter));
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=buildTree();
	// cout<<findHeight(root)<<endl;
	// cout<<findTotalNodes(root)<<endl;
	// preorderPrint(root);
	// cout<<endl;
	// inorderPrint(root);
	// cout<<endl;
	// postorderPrint(root);
	// levelOrderPrintOptimized(root);
	int num=0;
	cout<<diameterOptimized(root,&num);
	return 0;
}

//input-> 0 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 10 -1 -1 2 5 11 -1 -1 -1 6 -1 -1