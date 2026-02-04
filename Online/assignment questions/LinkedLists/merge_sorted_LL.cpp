// MERGE SORTED LINKED LISTS
// Given 2 sorted linked lists , Merge the two given sorted linked list and print the final LinkedList.

// Input Format:
// First Line contains T the number of test cases. For each test case : Line 1 : N1 the size of list 1 Line 2 : N1 elements for list 1 Line 3 : N2 the size of list 2 Line 4 : N1 elements for list 2

// Constraints:
// 1 <= T <= 1000 0<= N1, N2 <= 10^6 -10^7 <= Ai <= 10^7

// Output Format
// T lines of merged output

// Sample Input
// 1
// 4
// 1 3 5 7
// 3
// 2 4 6
// Sample Output
// 1 2 3 4 5 6 7 

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
		curr->next=merge(head1->next,head2);
	}
	else
	{
		curr=head2;
		curr->next=merge(head1,head2->next);
	}
	return curr;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		node*head1=NULL;
		node*head2=NULL;
		int n1,n2;
		cin>>n1;
		buildLL(head1,n1);
		cin>>n2;
		buildLL(head2,n2);
		head1=merge(head1,head2);
		print(head1);
		t--;
	}
	return 0;
}