// LL - K REVERSE
// Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

// You need not have to create a new list. Just reverse the old one using head.

// Input Format:
// The first line contains 2 space separated integers N and K

// The next line contains N space separated integral elements of the list.

// Constraints:
// 0 <= N <= 10^6 0 <= K <= 10^6

// Output Format
// Display the linkedlist after reversing every k elements

// Sample Input
// 9 3
// 9 4 1 7 8 3 2 6 5
// Sample Output
// 1 4 9 3 8 7 5 6 2

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

void insert(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node* newnode=new node(data);
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
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

void buildLL(node*&head,int n)
{
	int data;
	while(n>0)
	{
		cin>>data;
		insert(head,data);
		n--;
	}
}

node* K_Reverse(node*head,int k)
{
	if(head==NULL)
	{
		return head;
	}
	node* prev=NULL;
	node* curr=head;
	node* next;
	for(int i=0;i<k && curr!=NULL;i++)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	node* newhead=K_Reverse(curr,k);
	head->next=newhead;
	return prev;
}

int main() {
	node* head=NULL;
	int n,k;
	cin>>n>>k;
	buildLL(head,n);
	print(head);
	head=K_Reverse(head,k);
	print(head);
	return 0;
}