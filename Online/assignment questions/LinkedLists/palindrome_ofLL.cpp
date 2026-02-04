// PALINDROME
// Check if a linked list is a palindrome.( Boolean return type )

// Input Format:
// Add N space separated elements in the list

// Constraints:
// None

// Output Format
// Boolean answer( true or false)

// Sample Input
// 5
// 1 2 3 6 8
// Sample Output
// False

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

node* copyLL(node* head)
{
	node* temp=NULL;
	while(head!=NULL)
	{
		insert(temp,head->data);
		head=head->next;
	}
	return temp;
}

bool palindrome(node*head)
{
	node* head1=NULL;
	head1=copyLL(head);
	reverseIterative(head1);
	while(head!=NULL && head1!=NULL)
	{
		if(head->data!=head1->data)
		{
			return false;
		}
		head=head->next;
		head1=head1->next;
	}
	return true;
}

int main() {
	node* head=NULL;
	int n;
	cin>>n;
	buildLL(head,n);
	if(palindrome(head))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}