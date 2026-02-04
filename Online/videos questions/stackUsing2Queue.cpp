//Stack using two queue
#include <iostream>
#include <queue>
using namespace std;

// //this stack is push efficient but pop costlier 
// class Stack
// {
// private:
// 	queue<int> *q1,*q2;
// public:
// 	Stack()
// 	{
// 		q1=new queue<int>;
// 		q2=new queue<int>;
// 	}

// 	//Always pushing in q1
// 	void push(int data)
// 	{
// 		q1->push(data);
// 	}

// 	void pop()
// 	{
// 		int s=q1->size();
// 		for(int i=0;i<s-1;i++)
// 		{
// 			q2->push(q1->front());
// 			q1->pop();
// 		}
// 		if(!q1->empty())
// 			q1->pop();
// 		swap(q1,q2);//because we are always pushing in q1
// 	}

// 	int top()
// 	{
// 		int s=q1->size();
// 		int topEle;
// 		for(int i=0;i<s;i++)
// 		{
// 			topEle=q1->front();
// 			q2->push(topEle);
// 			q1->pop();
// 		}
// 		swap(q1,q2);
// 		return topEle;
// 	}
// };


//this stack is pop efficient but push costlier 
class Stack
{
private:
	queue<int> *q1,*q2;
public:
	Stack()
	{
		q1=new queue<int>;
		q2=new queue<int>;
	}

	void push(int data)
	{
		q2->push(data);
		while(!q1->empty())
		{
			q2->push(q1->front());
			q1->pop();
		}

		swap(q1,q2);
	}

	void pop()
	{
		q1->pop();
	}

	int top()
	{
		return q1->front();
	}
};

int main(int argc, char const *argv[])
{
	Stack st;
	for(int i=10;i>=1;i--)
	{
		st.push(i);
	}
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();

	return 0;
}