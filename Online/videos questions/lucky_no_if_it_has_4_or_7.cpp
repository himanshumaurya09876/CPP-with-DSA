#include <iostream>
#include <string>

using namespace std;

int findIndex(string num)
{
    int l=num.length();
    int ans=(1<<l)-2;
    int pos=0;
    for(int i=l-1;i>=0;i--,pos++)
    {
        if(num[i]=='7')
        {
            ans+=(1<<pos);
        }
    }
    ans+=1;
    return ans;
}

int main()
{
    string num;
    cout<<"Enter a lucky number whose index you want: ";
    cin>>num;
    cout<<"Its index is: "<<findIndex(num);
    return 0;
}
