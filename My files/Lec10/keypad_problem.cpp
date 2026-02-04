#include <iostream>

using namespace std;

string key[10]={"Z","*","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXY"};

void printcomb(string n,string output="")
{
    if(n=="")
    {
        cout<<output<<endl;
        return;
    }
    else
    {
        int m=n[0]-'0';
        int l=key[m].length();
        for(int i=0;i<l;i++)
            printcomb(n.substr(1),output+key[m][i]);
    }
}

int main()
{
    string num;
    cout <<"Enter a number: ";
    cin>>num;
    printcomb(num);
    return 0;
}
