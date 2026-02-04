#include <iostream>
#include <string>

using namespace std;
/*generate alphabet using
char ch=char('A'+n1 or n2-1);*/
string alphabet[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

void printwords(string input,string output="")
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    int n1=input[0]-'0';
    int n2=(input[0]-'0')*10+(input[1]-'0');//int n2=stoi(input.substr(0,2));
    printwords(input.substr(1),output+alphabet[n1-1]);
    if(n2<=26 && input.length()>=2)
    {
        printwords(input.substr(2),output+alphabet[n2-1]);
    }
}

int main()
{
    //string alphabets="gggggggggggggggggggggggggg";
    string num;
    /*int i;
    for(i=0;i<26;i++)
    {
        alphabets[i]=char(65+i);
    }
    cout<<alphabets<<endl;*/
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Possible words are: "<<endl;
    printwords(num);
    return 0;
}
