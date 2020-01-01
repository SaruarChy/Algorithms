#include<iostream>
#include<string>
using namespace std;

void permutations(string str, int l, int r)
{
    if(l == r)
    {
        cout<<str<<endl;
    }
    else
    {
        for(int i=l; i<=r;i++)
        {
            //swapping done
            swap(str[l],str[i]);
            //recurtion called
            permutations(str,l+1,r);
            //backtrack
            swap(str[l],str[i]);
        }
    }
}

int main()
{
    string str;
    int n;
    cout<<"Enter a string\n";
    cin>>str;
    cout<<endl;
    n = str.size();
    permutations(str,0,n-1);
    return 0;
}
