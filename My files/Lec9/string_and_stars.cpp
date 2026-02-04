#include <iostream>
#include <string.h>

using namespace std;

void manipulate(string &str,string str1="",int i=0)
{
    if(i==str.size())
    {
        str=str1;
        return;
    }
    else
    {
        str1+=str[i];
        if(str[i]==str[i+1])
        {
            str1+='*';
        }
        manipulate(str,str1,i+1);
    }
}

int main()
{
    string str;
    int n;
    cout << "Enter a string: ";
    cin>>str;
    manipulate(str);///call by reference
    cout<<"Final string is: "<<str;
    return 0;
}
