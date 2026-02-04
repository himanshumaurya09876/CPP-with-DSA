#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin>>str;
    int s=str.length();///str.size();
    cout<<"Substrings are: "<<endl;
    for(int i=0;i<s;i++)
    {
        for(int j=i;j<s;j++)
        {
            string sub=str.substr(i,j-i+1);
            cout<<sub<<endl;
            /*for(int k=i;k<=j;k++)
            {
                cout<<str[k];
            }
            cout<<endl;*/
        }
    }
    return 0;
}
