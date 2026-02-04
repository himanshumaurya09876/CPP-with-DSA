// STRING SORT
// Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

// Input Format:
// N(integer) followed by N strings.

// Constraints:
// N<=1000

// Output Format
// N lines each containing one string.

// Sample Input
// 3
// bat
// apple
// batman
// Sample Output
// apple
// batman
// bat


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s[1000];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            int k=0,l1=s[j].length(),l2=s[j-1].length();
            char tag='n';
            while(k<l1 && k<l2)
            {
                if(int(s[j-1][k])>int(s[j][k]))
                {
                    string temp=s[j];
                    s[j]=s[j-1];
                    s[j-1]=temp;
                    tag='n';
                    break;
                }
                else if(int(s[j-1][k])<int(s[j][k]))
                {
                    tag='n';
                    break;
                }
                else
                {
                    tag='e';
                }
                k++;
            }
            if(s[j][k]!='/0' && tag=='e')
            {
                string temp=s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}