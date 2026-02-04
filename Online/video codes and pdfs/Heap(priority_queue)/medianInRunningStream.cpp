#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<float,vector<float>,greater<float> > pqMin;
	priority_queue<float> pqMax;
	float d;
	float median=-1;
	while(scanf("%f",&d)!=EOF)
	{
		if(d==-1)
		{
			cout<<median<<endl;
			continue;
		}

		if(d>median)
		{
			pqMin.push(d);
		}
		else
		{
			pqMax.push(d);
		}

		//calculate new median after balancing the heaps
		int sMin=pqMin.size();
		int sMax=pqMax.size();

		if(sMax==sMin)
		{
			median=(pqMax.top()+pqMin.top())/2;
		}
		else if(sMax-sMin==1)
		{
			median=pqMax.top();
		}
		else if(sMin-sMax==1)
		{
			median=pqMin.top();
		}
		else if(sMax-sMin==2)
		{
			pqMin.push(pqMax.top());
			pqMax.pop();
			median=(pqMax.top()+pqMin.top())/2;
		}
		else
		{
			pqMax.push(pqMin.top());
			pqMin.pop();
			median=(pqMax.top()+pqMin.top())/2;
		}
	}
	return 0;
}