#include <iostream>

using namespace std;

int main()
{
    char ch;
    int x=0,y=0;
    cout<<"Enter a path: ";
    ch=cin.get();
    while(ch!='\n')
    {
        switch(ch)
        {
            case 'N':y++;
                     break;
            case 'S':y--;
                     break;
            case 'E':x++;
                     break;
            case 'W':x--;
                     break;
        }
        ch=cin.get();
    }
    cout<<"The net displacement is x="<<x<<" and y="<<y<<endl;
    if(x==0 && y==0)
    {
        cout<<"At the origin"<<endl;
    }
    else if(x>=0 && y>=0)
    {
        for(int i=0;i<x;i++)
        {
            cout<<"E";
        }
        for(int i=0;i<y;i++)
        {
            cout<<"N";
        }
    }
    else if(x<=0 && y>=0)
    {
        for(int i=0;i<y;i++)
        {
            cout<<"N";
        }
        for(int i=0;i>x;i--)
        {
            cout<<"W";
        }
    }
    else if(x<=0 && y<=0)
    {
        for(int i=0;i>x;i--)
        {
            cout<<"W";
        }
        for(int i=0;i>y;i--)
        {
            cout<<"S";
        }
    }
    else
    {
        for(int i=0;i<x;i++)
        {
            cout<<"E";
        }
        for(int i=0;i>y;i--)
        {
            cout<<"S";
        }
    }
    return 0;
}
