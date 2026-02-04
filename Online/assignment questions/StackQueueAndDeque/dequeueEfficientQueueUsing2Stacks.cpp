// DEQUEUE EFFICIENT QUEUE USING STACK
// Implement a Queue using two stacks Make it Dequeue efficient.

// Input Format:
// Enter the size of the queue N add 0 - N-1 numbers in the queue

// Constraints:
// Output Format
// Display the numbers in the order they are dequeued and in a space separated manner

// Sample Input
// 5
// Sample Output
// 0 1 2 3 4




// #include <iostream>
// #include <stack>
// using namespace std;

// //Enqueue efficient Dequeue costlier
// class Queue
// {
// private:
// 	stack<int> *st1,*st2;
// public:
// 	Queue()
// 	{
// 		st1=new stack<int>;
// 		st2=new stack<int>;
// 	}

// 	void enQueue(int data)
// 	{
// 		st1->push(data);
// 	}

// 	void deQueue()
// 	{
// 		int s=st1->size();
// 		while(!st1->empty() && s>1)
// 		{
// 			st2->push(st1->top());
// 			st1->pop();
// 			s--;
// 		}

// 		st1->pop();

// 		while(!st2->empty())
// 		{
// 			st1->push(st2->top());
// 			st2->pop();
// 		}
// 	}

// 	int front()
// 	{
// 		int s=st1->size();
// 		while(!st1->empty() && s>1)
// 		{
// 			st2->push(st1->top());
// 			st1->pop();
// 			s--;
// 		}

// 		int frontEle=st1->top();

// 		while(!st2->empty())
// 		{
// 			st1->push(st2->top());
// 			st2->pop();
// 		}

// 		return frontEle;
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	Queue q;
// 	for(int i=1;i<=10;i++)
// 	{
// 		q.enQueue(i);
// 	}

// 	cout<<q.front()<<endl;
// 	q.deQueue();
// 	cout<<q.front()<<endl;
// 	q.deQueue();
// 	cout<<q.front()<<endl;
// 	q.deQueue();
// 	cout<<q.front()<<endl;
// 	q.deQueue();
// 	cout<<q.front()<<endl;
// 	q.deQueue();

// 	return 0;
// }




#include <iostream>
#include <stack>
using namespace std;

//Dequeue efficient Enqueue costlier
class Queue
{
private:
	stack<int> *st1,*st2;
public:
	Queue()
	{
		st1=new stack<int>;
		st2=new stack<int>;
	}

	void enQueue(int data)
	{
		while(!st1->empty())
		{
			st2->push(st1->top());
			st1->pop();
		}
		st1->push(data);
		while(!st2->empty())
		{
			st1->push(st2->top());
			st2->pop();
		}
	}

	void deQueue()
	{
		st1->pop();
	}

	int front()
	{
		return st1->top();
	}
};

int main(int argc, char const *argv[])
{
	Queue q;
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		q.enQueue(i);
	}

	for(int i=0;i<n;i++)
	{
		cout<<q.front()<<" ";
		q.deQueue();
	}

	return 0;
}