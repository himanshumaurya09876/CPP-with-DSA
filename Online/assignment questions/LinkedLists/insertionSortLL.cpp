// SORT LINKED LIST USING INSERTION SORT
// Given a linked list with n nodes. Sort the linked list using insertion sort.

// Input Format:
// First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.

// Constraints:
// n < 30

// Output Format
// Print the linked list after sorting it using insertion sort.

// Sample Input
// 5
// 2 3 4 1 5
// Sample Output
// 1 2 3 4 5

#include<iostream>
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

void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
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
	if(p==1 || head==NULL || head->next==NULL)
	{
		deleteAtHead(head);
	}
	else if(p>=length(head))
	{
		deleteAtTail(head);
	}
	else
	{
		int i=1;
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

void buildLL(node*&head,int n)
{
	int data;
	while(n>0)
	{
		cin>>data;
		insertAtTail(head,data);
		n--;
	}
}

void insertionSort(node*&head)
{
	node* temp=head;
	int i=1,j;
	int l=length(head);
	while(i<=l)
	{
		int k=i;
		temp=head;
		while(k-1>0)
		{
			temp=temp->next;
			k--;
		}
		node* temp1=head;
		j=0;
		while(temp1!=temp)
		{
			if(temp1->data>temp->data)
			{
				int data=temp->data;
				deleteAtPosition(head,i);
				insertAtPosition(head,data,j);
				// cout<<i<<" "<<j<<" "<<data<<endl;
				// print(head);
				// cout<<endl;
				break;
			}
			temp1=temp1->next;
			j++;
		}
		i++;
	}
}

int main() {
	node* head=NULL;
	int n;
	cin>>n;
	buildLL(head,n);
	insertionSort(head);
	//cout<<"hi"<<endl;
	print(head);
	return 0;
}