//linked list

#include <bits/stdc++.h>

using namespace std;

class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

int length(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		len++;
		head=head->next;
	}
	return len;
}

void insertAtHead(node* &head,int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	node* newnode=new node(d);
	newnode->next=head;
	head=newnode;
	return;
}

void insertAtTail(node* &head,int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* newnode=new node(d);
	temp->next=newnode;
	return;
}

void insertAtPosition(node* &head,int d,int p)
{
	if(p==0 || head==NULL)
	{
		insertAtHead(head,d);
	}
	else if(p>=length(head)-1)
	{
		insertAtTail(head,d);
	}
	else
	{
		int i=0;
		node* temp=head;
		while(i<p-1)
		{
			temp=temp->next;
			i++;
		}
		node* newnode=new node(d);
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return;
}

void deleteAtHead(node* &head)
{
	if(head==NULL)
	{
		return;
	}
	node* temp=head;
	head=head->next;
	delete temp;
	return;
}

void deleteAtTail(node* &head)
{
	if(head==NULL)
	{
		return;
	}
	node* temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	delete temp->next;
	temp->next=NULL;
	return;
}

void deleteAtPosition(node* &head,int p)
{
	if(p==0 || head==NULL || head->next==NULL)
	{
		deleteAtHead(head);
	}
	else if(p>=length(head)-1)
	{
		deleteAtTail(head);
	}
	else
	{
		int i=0;
		node* temp=head;
		while(i<p-1)
		{
			i++;
			temp=temp->next;
		}
		node* temp1=temp->next;
		temp->next=temp1->next;
		delete(temp1);
	}
	return;
}

void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}

void buildLinkedList(node*&head)
{
	int d;
	cin>>d;
	while(d!=-1)
	{
		insertAtTail(head,d);
		cin>>d;
	}
	return;
}

int searchIterative(node* head,int n)
{
	int i=0;
	if(head==NULL)
	{
		return -1;
	}
	while(head!=NULL)
	{
		if(head->data==n)
		{
			return i;
		}
		i++;
		head=head->next;
	}
	return -1;
}

int searchRecursive(node* head,int n,int i=0)
{
	if(head==NULL)
	{
		return -1;
	}
	else if(head->data==n)
	{
		return i;
	}
	else
	{
		return searchRecursive(head->next,n,i+1);
	}
}

void reverseIterative(node* &head)
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	node*prev=NULL,*curr=head,*nex=head->next;
	while(nex!=NULL)
	{
		curr->next=prev;
		prev=curr;
		curr=nex;
		nex=nex->next;
	}
	curr->next=prev;
	head=curr;
	return;
}

node* reverseRecursive(node* prev,node* curr,node* nex)
{
    //base case
    if(nex==NULL)
    {
        curr->next=prev;
        return curr;
    }
    //self work
    curr->next=prev;
    //recursive case
    return reverseRecursive(curr,nex,nex->next);
}

int main()
{
	node* head=NULL;
	// insertAtTail(head,100);
	// insertAtHead(head,10);
	// insertAtHead(head,50);
    // insertAtTail(head,100);
	// insertAtPosition(head,500,1);
	// print(head);
	buildLinkedList(head);
	cout<<endl;
	print(head);
	// insertAtHead(head,5);
	// insertAtTail(head,10);
	// cout<<endl;
	// print(head);
	// insertAtPosition(head,45,5);
	// insertAtHead(head,59);
	// insertAtTail(head,25);
	// cout<<endl;
	// print(head);
	// insertAtPosition(head,89,5);
	// cout<<endl;
	// print(head);
	// deleteAtHead(head);
	// deleteAtTail(head);
	// cout<<endl;
	// print(head);
	// deleteAtPosition(head,6);
	// cout<<endl;
	// print(head);
	// cout<<endl<<searchIterative(head,500);
	// cout<<endl<<searchIterative(head,45);
	// cout<<endl<<searchRecursive(head,500);
	// cout<<endl<<searchRecursive(head,45)<<endl;
	// cout<<endl;
	// print(head);
	// reverseIterative(head);
	// cout<<endl;
	// print(head);
	head=reverseRecursive(NULL,head,head->next);
	cout<<endl;
	print(head);
	return 0;
}
