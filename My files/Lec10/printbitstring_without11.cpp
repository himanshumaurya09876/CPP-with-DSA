#include <iostream>
#include <string>

using namespace std;

void stringprint(int n,string s="")
{
    if(n==0)
    {
        cout<<s<<endl;
        return;
    }
    else
    {
        if(s[s.length()-1]=='1')
        {
            stringprint(n-1,s+'0');
        }
        else
        {
            stringprint(n-1,s+'1');
            stringprint(n-1,s+'0');
        }
    }
}

int stringcount(int n,string s="")
{
    int count;
    if(n==0)
    {
        return 1;
    }
    else
    {
        count=0;
        if(s[s.length()-1]=='1')
        {
            count+=stringcount(n-1,s+'0');
        }
        else
        {
            count+=stringcount(n-1,s+'1')+stringcount(n-1,s+'0');
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Total combinations are: "<<stringcount(n)<<endl;
    stringprint(n);
    return 0;
}
