#include <iostream>
#include <vector>
using namespace std;

class heap
{
private:
	vector<int> v;
	bool isMinHeap;

	bool compare(int a,int b)
	{
		if(isMinHeap)
		{
			return a<b;
		}
		return a>b;
	}

	void heapify(int idx=1)
	{
		int lc=2*idx;
		int rc=2*idx+1;

		int minmp=idx;

		if(lc<v.size() && compare(v[lc],v[minmp]))
		{
			minmp=lc;
		}

		if(rc<v.size() && compare(v[rc],v[minmp]))
		{
			minmp=rc;
		}

		if(minmp!=idx)
		{
			swap(v[minmp],v[idx]);
			heapify(minmp);
		}
	}
public:
	heap(bool choice=true)
	{
		isMinHeap=choice;
		v.push_back(-1);//we are starting vector from index=1
		// so for parent at i leftchild -> 2*i and rightchild -> 2*i+1
	}

	void push(int data)
	{
		v.push_back(data);
		int childIdx=v.size()-1;
		int parentIdx=childIdx/2;
		while(childIdx>1 && compare(v[childIdx],v[parentIdx]))
		{
			swap(v[childIdx],v[parentIdx]);
			childIdx=parentIdx;
			parentIdx=childIdx/2;
		}
	}

	int top()
	{
		if(v.size()>1)
		{
			return v[1];
		}
		return -1;
	}

	void pop()
	{
		if(v.size()<=1)
		{
			return;
		}

		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}

	bool empty()
	{
		if(v.size()==1)
		{
			return true;
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	heap hp(false);
	hp.push(5);
	hp.push(69);
	hp.push(20);
	hp.push(0);
	hp.push(48);
	hp.push(34);
	hp.push(9);

	while(!hp.empty())
	{
		cout<<hp.top()<<endl;
		hp.pop();
	}
	return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;
// //Implementation of Heap using Vector(Dynamic Array)

// class Heap{
//         vector<int> v;
//         //Configuration 
//         bool minHeap;

//         bool compare(int a,int b){
//             if(minHeap){
//                 return a<b;
//             }
//             else{
//                 return a>b;
//             }
//         }
//         void heapify(int i){
//             int left = 2*i;
//             int right = 2*i + 1;

//             //Assume current is min
//             int minIndex = i;
//             if(left < v.size() && compare(v[left],v[i])){
//                 minIndex = left;
//             }
//             if(right < v.size() && compare(v[right],v[minIndex])){
//                 minIndex = right;
//             }

//             if(minIndex!=i){
//                 swap(v[i],v[minIndex]);
//                 heapify(minIndex);
//             }
//         }

//     public:
//         Heap(bool type=true){
//             minHeap = type;
//             //Block the 0th index
//             v.push_back(-1);
//         }

//         void push(int data){
//             //Insert at Last
//             v.push_back(data);
//             //Take that element to correct position restore the heap property
//             int index = v.size() - 1;
//             int parent = index/2;

//             while(index>1 && compare(v[index],v[parent]) ){
//                 swap(v[index],v[parent]);
//                 index = parent;
//                 parent = parent/2;
//             }
//         }
//         bool empty(){
//             return v.size()==1;
//         }

//         int top(){
//             return v[1];
//         }

//         void pop(){
//             //Remove the topmost element
//             int last = v.size() - 1;
//             swap(v[1],v[last]);
//             v.pop_back();
//             heapify(1);
//         }

// };


// int main() {

//     Heap h(true);
//     h.push(5);
//     h.push(15);
//     h.push(2);
//     h.push(20);
//     h.push(3);

//     //cout<<h.top()<<endl;
//     while(!h.empty()){
//         cout<<h.top()<<endl;
//         h.pop();
//     }


//     return 0;
// }
