#include <iostream>

using namespace std;

void reverse(char ch[30],int i,int j)
{
    while(i<j)
    {
        char temp;
        temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;
        j--;
        i++;
    }
}

int main()
{
    char *ch=new char[30];
    int i=0,j=0;
    cout<<"Enter a string: ";
    cin.getline(ch,30);
    for(int k=0;k<30;k++)
    {
        if(ch[k]==' ')
        {
            j=k;
            reverse(ch,i,j);
            i=j;
        }
    }
    cout<<"\nFinal string is: "<<ch;
    return 0;
}
