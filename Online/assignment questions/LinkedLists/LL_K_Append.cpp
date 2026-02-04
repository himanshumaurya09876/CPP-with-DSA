// LINKED LIST-K APPEND
// Append the last K elements of a linked list to the front.K can be greater than N.

// Input Format:
// Enter the size N, N space separated elements and number of elements that are to be appended(n).

// Constraints:
// None

// Output Format
// Display all the elements in the list

// Sample Input
// 7
// 1 2 2 1 8 5 6
// 3
// Sample Output
// 8 5 6 1 2 2 1

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

node* K_Append(node*head,int k)
{
	node*slow=head;
	node*fast=head;
	while(k>0)
	{
		if(fast==NULL)
		{
			return head;
		}
		fast=fast->next;
		k--;
	}
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	node*temp=slow->next;
	fast->next=head;
	slow->next=NULL;
	return temp;
}

int main() {
	node* head=NULL;
	int n,k;
	cin>>n;
	buildLL(head,n);
	cin>>k;
	head=K_Append(head,k);
	print(head);
	return 0;
}