// EVEN-AFTER-ODD
// Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

// Input Format:
// Enter N space separated Elements

// Constraints:
// None

// Output Format
// Linked list with all the odd numbers before even numbers

// Sample Input
// 5
// 1 2 2 2 1
// Sample Output
// 1 1 2 2 2

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

node* evenAfterOdd(node*head)
{
	if(head==NULL)
	{
		return head;
	}
	node* evenhead=NULL;
	node* oddhead=NULL;
	node* even=NULL;
	node* odd=NULL;
	while(head!=NULL)
	{
		if(head->data % 2)
	 	{
			if(oddhead==NULL)
			{
				oddhead=head;
				odd=oddhead;
			}
			else
			{
				odd->next=head;
				odd=head;
			}
		}
		else
		{
			if(evenhead==NULL)
			{
				evenhead=head;
				even=evenhead;
			}
			else
			{
				even->next=head;
				even=head;
			}
		}
		head=head->next;
	}
	if(odd==NULL)
	{
		even->next=NULL;
		return evenhead;
	}
	else if(even==NULL)
	{
		odd->next=NULL;
		return oddhead;
	}
	odd->next=evenhead;
	even->next=NULL;
	return oddhead;
}

int main() {
	node* head=NULL;
	int n;
	cin>>n;
	buildLL(head,n);
	head=evenAfterOdd(head);
	print(head);
	return 0;
}