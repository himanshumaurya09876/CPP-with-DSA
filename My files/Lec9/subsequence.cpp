#include <iostream>
#include <string>

using namespace std;

void subsequence(string input,string output="")
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    char ch=input[0];
    input=input.substr(1);
    subsequence(input,output+ch);
    subsequence(input,output);
}

int main()
{
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"Subsequences are: "<<endl;
    subsequence(str);
    return 0;
}
