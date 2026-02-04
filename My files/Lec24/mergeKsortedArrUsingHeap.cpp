#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int,int> > pp;

vector<int> mergeKarrays(vector<vector<int> > arrays)
{
	priority_queue<pp,vector<pp>,greater<pp> > pq;
	vector<int> finalArr;
	int rows=arrays.size();
	for(int i=0;i<rows;i++)
	{
		pp p=make_pair(arrays[i][0],make_pair(i,0));
		pq.push(p);
	}
	while(!pq.empty())
	{
		pp p=pq.top();
		pq.pop();
		int num=p.first;
		int arrNo=p.second.first;
		int col=p.second.second;
		finalArr.push_back(num);
		col++;
		if(col<arrays[arrNo].size())
		{
			p=make_pair(arrays[arrNo][col],make_pair(arrNo,col));
			pq.push(p);	
		}
	}
	return finalArr;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > arrays={{5,9,18,20,61},
								 {6,11,22},
								 {19,54,100,101},
								 {1,3,10}};
	vector<int> finalArr=mergeKarrays(arrays);
	for(auto it:finalArr)
	{
		cout<<it<<" ";
	} 
	cout<<endl;
	return 0;
}