
#include <bits/stdc++.h>

using namespace std;

class node
{
	public:
		int data;
		node* down;
		node* right;
		node(int d)
		{
			data=d;
			down=NULL;
			right=NULL;
		}
};

void insertDown(node* &head,int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	node* temp=head;
	while(temp->down!=NULL)
	{
		temp=temp->down;
	}
	node* newnode=new node(d);
	temp->down=newnode;
	return;
}

void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->down;
	}
	cout<<endl;
	return;
}

node* merge(node* head1,node* head2)
{
	if(head1==NULL)
	{
		return head2;
	}
	else if(head2==NULL)
	{
		return head1;
	}
	node* curr;
	if(head1->data<head2->data)
	{
		curr=head1;
		curr->down=merge(head1->down,head2);
	}
	else
	{
		curr=head2;
		curr->down=merge(head1,head2->down);
	}
	return curr;
}

node* mergeSpecialLL(node* head)
{
	if(head==NULL || head->right==NULL)
	{
		return head;
	}
	node* curr=head;
	node* rightres=mergeSpecialLL(head->right);
	return merge(curr,rightres);
}

int main()
{
	node* head=NULL;
	insertDown(head,3);
	insertDown(head,9);
	insertDown(head,10);
	insertDown(head,11);
	insertDown(head->right,9);
	insertDown(head->right,11);
	insertDown(head->right,16);
	insertDown(head->right->right,5);
	insertDown(head->right->right,6);
	insertDown(head->right->right,7);
	insertDown(head->right->right->right,1);
	insertDown(head->right->right->right,2);
	insertDown(head->right->right->right,4);
	mergeSpecialLL(head);
	print(head);
	return 0;
}