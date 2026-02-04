#include <iostream>
#include <queue>
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

node* buildTree()
{
	int data;
	cin>>data;

	if(data==-1)
	{
		return NULL;
	}

	node* root=new node(data);
	root->lc=buildTree();
	root->rc=buildTree();
	return root;
}

int height(node* root)
{
	if(root==NULL)
	{
		return -1;
	}

	return max(height(root->lc),height(root->rc))+1;
}

void printLevelK(node* root,int k)
{
	if(root==NULL)
	{
		return;
	}

	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}

	printLevelK(root->lc,k-1);
	printLevelK(root->rc,k-1);
}

void levelOrderPrint(node* root)
{
	int h=height(root);
	// cout<<"Height: "<<h<<endl;
	for(int i=0;i<=h;i++)
	{
		printLevelK(root,i);
		cout<<endl;
	}
}

void bfs(node* root)//breadth first search
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* nd=q.front();
		q.pop();

		cout<<nd->data<<" ";

		if(nd->lc!=NULL)
		{
			q.push(nd->lc);
		}
		if(nd->rc!=NULL)
		{
			q.push(nd->rc);
		}
	}
	cout<<endl;
}

void bfs1(node* root)//breadth first search
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* nd=q.front();
		q.pop();
		if(nd==NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}

		else
		{
			cout<<nd->data<<" ";

			if(nd->lc!=NULL)
			{
				q.push(nd->lc);
			}
			if(nd->rc!=NULL)
			{
				q.push(nd->rc);
			}
		}
	}
}

int countNodes(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return countNodes(root->lc)+countNodes(root->rc)+1;
}

int sumOfNodes(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return root->data+sumOfNodes(root->lc)+sumOfNodes(root->rc);
}

int diameter(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int hl=height(root->lc);
	int hr=height(root->rc);

	int currd=hl+hr+2;
	int leftd=diameter(root->lc);
	int rightd=diameter(root->rc);

	return max(currd,max(leftd,rightd));
}

pair<int,int> diameterOpt(node* root)
{
	pair<int,int> curr;
	if(root==NULL)
	{
		curr.first=0;
		curr.second=-1;
		return curr;
	}
	//in first->diameter
	//in second->height
	pair<int,int> left=diameterOpt(root->lc);
	pair<int,int> right=diameterOpt(root->rc);

	curr.first=max(left.second+right.second+2,max(left.first,right.first));
	curr.second=max(left.second,right.second)+1;

	return curr;
}

int replaceNodeBySumOfChildNodes(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int left=replaceNodeBySumOfChildNodes(root->lc);
	int right=replaceNodeBySumOfChildNodes(root->rc);

	if(root->lc==NULL && root->rc==NULL)
	{
		return root->data;
	}

	int curr=root->data;
	root->data=left+right;

	return curr+root->data;
}


int main(int argc, char const *argv[])
{
	node* root=buildTree();
	// levelOrderPrint(root);
	// bfs(root);
	// bfs1(root);
	// cout<<countNodes(root)<<" "<<sumOfNodes(root)<<endl;
	// cout<<diameter(root)<<endl;
	// pair<int,int> ans=diameterOpt(root);
	// cout<<ans.first<<" "<<ans.second<<endl;
	replaceNodeBySumOfChildNodes(root);
	levelOrderPrint(root);
	return 0;
}

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1