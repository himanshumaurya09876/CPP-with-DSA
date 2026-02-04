#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int weight[]={4,6,1,8,50,10,3,7};
	int price[]={200,305,250,20,2000,2,36,129};
	int bagwt=25;

	int n=8;
	pair<float,int> priceperwt[8];
	for(int i=0;i<n;i++)
	{
		priceperwt[i]=make_pair((float)price[i]/weight[i],i);
	}

	sort(priceperwt,priceperwt+n);

	float sum=0;
	int i;
	for(i=n-1;i>=0 && bagwt>0;i--)
	{
		sum+=price[priceperwt[i].second];
		bagwt-=weight[priceperwt[i].second];
		// cout<<sum<<" "<<i<<endl;
	}
	if(i>=0)
	{
		i++;
		sum-=price[priceperwt[i].second];
		// cout<<sum<<" "<<i<<endl;
		bagwt+=weight[priceperwt[i].second];
		sum+=priceperwt[i].first*bagwt;
	}

	cout<<sum<<endl;
	return 0;
}