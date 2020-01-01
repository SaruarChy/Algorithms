#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> notprime(n);

    for(int i = 2; i< notprime.size();++i)
    {
        for(int j=i*i; j< notprime.size(); j+=i)
        {
            notprime[j] = 1;
        }
    }
    for(int i = 2; i< notprime.size();++i)
    {
        if(notprime[i]==0)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}



