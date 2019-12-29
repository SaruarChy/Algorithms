#include<iostream>
#include<string>
using namespace std;
string x,y;

int min(int a, int b)
{
    return (a<b) ? a : b;
}
int editdistance(int m,int n)
{
    int dp[m+1][n+1];
    int i,j;
    for(i=0; i<=m;i++)
       dp[i][0] = i;
    for(j=0; j<=n;j++)
      dp[0][j] = j;
    for(i=1; i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i] == y[j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
            }
        }
    }
    return dp[m][n];

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
    cout<<"Minimum number of edit opertion required for transforming"<<endl;
    cout<<"source string to destination string is "<<editdistance(m,n)<<endl;
    return 0;
}
