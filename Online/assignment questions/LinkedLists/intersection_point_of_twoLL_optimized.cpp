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

node* intersection(node*head1,node*head2)
{
	int l1=length(head1);
	int l2=length(head2);
	int d;
	char flag='n';
	node* ans=NULL;
	if(l1>l2)
	{
		d=l1-l2;
	}
	else
	{
		d=l2-l1;
		swap(head1,head2);
	}
	while(d>0)
	{
		head1=head1->next;
		d--;
	}
	// print(head1);
	// print(head2);
	while(head1!=NULL || head2!=NULL)
	{
		if(head1==NULL || head2==NULL)
		{
			return NULL;
		}
		if(flag=='n' && head1->data==head2->data)
		{
			flag='y';
			ans=head1;
		}
		if(flag=='y' && head1->data!=head2->data)
		{
			flag='n';
		}
		//cout<<head1->data<<" "<<head2->data<<" "<<flag<<endl;
		head1=head1->next;
		head2=head2->next;
	}
	if(flag=='y')
	{
		return ans;
	}
	else
	{
		return NULL;
	}
}

int main() {
	node* head1=NULL;
	node* head2=NULL;
	int n1,n2;
	cin>>n1;
	buildLL(head1,n1);
	cin>>n2;
	buildLL(head2,n2);
	//cout<<intersection(head1,head2)->data<<endl;
	node* ans=intersection(head1,head2);
	//cout<<"hi"<<endl;
	if(ans==NULL)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans->data<<endl;
	}
	return 0;
}