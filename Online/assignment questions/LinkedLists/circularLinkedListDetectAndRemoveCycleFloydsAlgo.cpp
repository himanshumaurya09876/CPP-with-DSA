// CIRCULAR LINKED LIST
// We are given a linked list which contains a cycle. Detect that cycle and break it. Print the linked list after removing the cycle.

// Input Format:
// The first line contains space separated integers. The integers are such that all the values are distinct but the value start repeating once the cycle gets completed. The list of integers given ends when -1 is input.

// Constraints:
// n < 10^5 where n is the length of list without the cycle

// Output Format
// Output single line containing space separated integers representing the list

// Sample Input
// 1 2 3 4 5 2 3 -1
// Sample Output
// 1 2 3 4 5

#include <iostream>
using namespace std;

class node
{
 public:
	int data;
	node* next;

	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

void insert(node* &head,int data,bool &isCycleFormed)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}

	node* temp=head;
	node* same=NULL;
	if(head->data==data)
	{
		same=head;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->data==data)
		{
			same=temp;
		}
	}
	if(same!=NULL)
	{
		temp->next=same;
		isCycleFormed=true;
		return;
	}

	node* newnode=new node(data);
	temp->next=newnode;
	isCycleFormed=false;
}

node* buildLL()
{
	int d;
	bool isCycleFormed=false;
	node* head=NULL;
	cin>>d;
	while(d!=-1)
	{
		if(!isCycleFormed)
			insert(head,d,isCycleFormed);
		cin>>d;
	}
	return head;
}

void removeCycle(node* &head)//floyd's algorithm
{
	if(head==NULL)
	{
		return;
	}

	node* slow=head;
	node* fast=head;
	bool isExist=false;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			isExist=true;
			break;
		}
	}

	if(!isExist)
	{
		return;
	}

	slow=head;
	if(fast!=head)
	{
		while(slow->next!=fast->next)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	else
	{
		while(fast->next!=head)
		{
			fast=fast->next;
		}
	}
	fast->next=NULL;
}

void printLL(node* head)
{
	if(head==NULL)
	{
		return;
	}

	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main(int argc, char const *argv[])
{
	node* head=buildLL();
	removeCycle(head);
	printLL(head);
	return 0;
}
