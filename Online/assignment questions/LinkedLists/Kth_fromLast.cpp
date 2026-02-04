// KTH ELEMENT FROM LAST IN LINKED LIST
// Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

// Input Format:
// First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

// Constraints:
// n < 10^5

// Output Format
// Output a single line containing the node value at the kth element from last.

// Sample Input
// 1 2 3 4 5 6 -1
// 3
// Sample Output
// 4

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

void buildLL(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insert(head,data);
		cin>>data;
	}
}

node* KthFromLast(node*head,int k)
{
	if(head==NULL)
	{
		return head;
	}
	node* slow=head;
	node* fast=head;
	while(k>0)
	{
		if(fast==NULL)
		{
			return head;
		}
		fast=fast->next;
		k--;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

int main() {
	node* head=NULL;
	buildLL(head);
	int k;
	cin>>k;
	cout<<KthFromLast(head,k)->data<<endl;
	return 0;
}