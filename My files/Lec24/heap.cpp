//heap ->also a binary tree
#include <iostream>
#include <vector>
using namespace std;

class heap//or priority_queue
{
private:
	vector<int> pqueue;
	bool minheap;

	bool compare(int a,int b)
	{
		if(minheap)
		{
			return a>b;
		}
		return a<b;
	}

	void heapify(int idx=1)//heapification or heapify is to make a heap using distorted heap
	{
		int leftidx=2*idx;
		int rightidx=2*idx+1;
		int totalsize=pqueue.size();
		int mostPriorityIdx=idx;

		if(leftidx<totalsize && compare(pqueue[mostPriorityIdx],pqueue[leftidx]))
		{
			mostPriorityIdx=leftidx;
		}
		if(rightidx<totalsize && compare(pqueue[mostPriorityIdx],pqueue[rightidx]))
		{
			mostPriorityIdx=rightidx;
		}

		if(mostPriorityIdx!=idx)
		{
			swap(pqueue[mostPriorityIdx],pqueue[idx]);
			heapify(mostPriorityIdx);
		}
	}

public:
	heap(bool choice=true)
	{
		minheap=choice;
		pqueue.push_back(-1);
	}

	bool isempty()
	{
		return pqueue.size()<=1;
	}

	int top()
	{
		if(isempty())
		{
			return -1;
		}
		return pqueue[1];
	}

	void push(int data)
	{
		int idx=pqueue.size();
		pqueue.push_back(data);

		int parent_idx=idx/2;
		while(idx>1 && compare(pqueue[parent_idx],pqueue[idx]))
		{
			swap(pqueue[parent_idx],pqueue[idx]);
			idx=parent_idx;
			parent_idx=idx/2;
		}
	}

	void pop()
	{
		if(isempty())
		{
			return;
		}
		int data=pqueue[1];
		pqueue[1]=pqueue[pqueue.size()-1];
		pqueue.pop_back();
		heapify();
	}
};

void heapsort(int arr[],int n,bool choice=true)
{
	heap h(choice);
	//both loops have O(nlogn) complexity
	for(int i=0;i<n;i++)
	{
		h.push(arr[i]);
	}		
	for(int i=0;i<n;i++)
	{
		arr[i]=h.top();
		h.pop();
	}
}

int main(int argc, char const *argv[])
{
	// heap hmin;//for min heap
	// heap hmax(false);//for max heap
	
	// //for min heap
	// hmin.push(5);
	// hmin.push(50);
	// hmin.push(45);
	// hmin.push(52);
	// hmin.push(95);
	// hmin.push(01);
	// hmin.push(55);
	// hmin.push(89);

	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// cout<<hmin.top()<<endl;
	// hmin.pop();
	// if(hmin.isempty())
	// {
	// 	cout<<"Empty"<<endl;
	// }
	// else
	// {
	// 	cout<<"Non empty"<<endl;
	// }

	// cout<<hmin.top()<<endl;
	// hmin.pop();

	// if(hmin.isempty())
	// {
	// 	cout<<"Empty"<<endl;
	// }
	// else
	// {
	// 	cout<<"Non empty"<<endl;
	// }
	// cout<<"====================================================="<<endl;

	// //for max heap
	// hmax.push(5);
	// hmax.push(50);
	// hmax.push(45);
	// hmax.push(52);
	// hmax.push(95);
	// hmax.push(01);
	// hmax.push(55);
	// hmax.push(89);

	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// if(hmax.isempty())
	// {
	// 	cout<<"Empty"<<endl;
	// }
	// else
	// {
	// 	cout<<"Non empty"<<endl;
	// }

	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// cout<<hmax.top()<<endl;
	// hmax.pop();
	// if(hmax.isempty())
	// {
	// 	cout<<"Empty"<<endl;
	// }
	// else
	// {
	// 	cout<<"Non empty"<<endl;
	// }

	// cout<<hmax.top()<<endl;
	// hmax.pop();

	// if(hmax.isempty())
	// {
	// 	cout<<"Empty"<<endl;
	// }
	// else
	// {
	// 	cout<<"Non empty"<<endl;
	// }

	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n,false);//for descending order
	//heapsort(arr,n);//for ascending order
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}