#include <iostream>
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

void reverseRecursive(node* &head,node* prev,node* curr,node* nex)
{
    //base case
    if(nex==NULL)
    {
        curr->next=prev;
        head=curr;
        return;
    }
    //self work
    curr->next=prev;
    //recursive case
    reverseRecursive(head,curr,nex,nex->next);
    return;
}

int main() {
    node* head=NULL;
    buildLinkedList(head);
	cout<<endl;
	print(head);
    reverseRecursive(head,NULL,head,head->next);
	cout<<endl;
	print(head);
	return 0;
}
