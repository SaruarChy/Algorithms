#include<iostream>
//#include<string>
#include<cstring>
using namespace std;
string x,y;
int dp[100][100];
int min(int a, int b)
{
    return (a<b) ? a : b;
}
int editdistance(int i,int j)
{
    if(i==0)
    return dp[i][j]=j;
    if(j==0)
    return dp[i][j]=i;
    if(dp[i][j] != -1)
     return dp[i][j];
    if(x[i] == y[j])
     return dp[i][j] = editdistance(i-1, j-1);
    else
    return dp[i][j] =  1+min(min(editdistance(i-1,j-1),editdistance(i-1,j)),editdistance(i,j-1));
}


int main()
{
    int m,n,i,j;
    cout<<"Enter source string"<<endl;
    cin>>x;
    cout<<"Enter destination string"<<endl;
    cin>>y;
    m = x.length();
    n = y.length();
    memset(dp,-1,sizeof(dp));
    cout<<"Minimum number of edit opertion required for transforming"<<endl;
    cout<<"source string to destination string is "<<editdistance(m,n)<<endl;
    return 0;
}
