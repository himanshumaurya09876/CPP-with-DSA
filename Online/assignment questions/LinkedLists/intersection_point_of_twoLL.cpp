// INTERSECTION POINT TWO LINKED LISTS
// There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.

// Input Format:
// The first line of input is the size(N1) of the first linked list, followed by its content(Xi). The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

// Constraints:
// 1<=N, N2<=100 0<=Xi, Yi<=100

// Output Format
// A single integer denoting the intersection point of two linked lists. If the linked lists are not intersecting at any point then print -1.

// Sample Input
// 5
// 10 20 30 40 50
// 4
// 15 25 40 50
// Sample Output
// 40

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

node* intersection(node* head1,node* head2)
{
	node* temp1=head1;
	node* temp2=head2;
	while(temp1!=NULL)
	{
		temp2=head2;
		//cout<<temp1->data<<endl;
		while(temp2!=NULL)
		{
			//cout<<temp2->data<<endl;
			if(temp2->data==temp1->data)
			{
				char flag='n';
				node* ptr1=temp1;
				node* ptr2=temp2;
				while(ptr1!=NULL || ptr2!=NULL)
				{
					//cout<<ptr1->data<<" "<<ptr2->data<<endl;
					// if(ptr1==NULL || ptr2==NULL)
     				// {
     				// 		flag='n';
     				//      break;
     				// }
					if(ptr1->data!=ptr2->data)
					{
						flag='y';
						break;
					}
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				if(flag=='n')
				{
					return temp1;
				}
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	return NULL;
}

int main() {
	node* head1=NULL;
	node* head2=NULL;
	int n1,n2;
	cin>>n1;
	buildLL(head1,n1);
	cin>>n2;
	buildLL(head2,n2);
	// cout<<intersection(head1,head2)->data<<endl;
	node* ans=intersection(head1,head2);
	// cout<<"hi"<<endl;
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