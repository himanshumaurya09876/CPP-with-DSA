#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int even=0,odd=0,num;
        cin>>num;
        while(num>0)
        {
            int d;
            d=num%10;
            if(d%2==0)
                even=even+d;
            else
                odd=odd+d;
            num=num/10;
        }
        if(even%4==0 || odd%3==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}