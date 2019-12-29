#include<iostream>
#include<cstring>
using namespace std;
int dp[100][100];

int maximum(int a, int b)
{
    return (a>b)? a: b;
}
int knapsack(int m,int w[],int p[],int n)
{
    int i,j;
    if(n==0 || m==0)
     return dp[n][m]=0;
    if(dp[n-1][m] != -1)
      return dp[n-1][m];
    if(w[n-1] > m)
    {
        return dp[n-1][m] = knapsack(m,w,p,n-1);
    }
    else
    {
        return dp[n-1][m] = maximum(p[n-1]+knapsack(m-w[n-1],w,p,n-1),knapsack(m,w,p,n-1));
    }
}
int main()
{
    int i,m,n,maxprice;
    int w[100],p[100];
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack: ";
    cin>>m;
    memset(dp,-1,sizeof(dp));
    cout<<"Enter the details of items\n";
    cout<<"Weight Price\n";
    for(i=1;i<=n;i++)
    {
        cin>>w[i]>>p[i];
    }

    maxprice = knapsack(m,w,p,n);
    cout<<"Maximum Profit "<<maxprice<<endl;
    cout<<"Selected items are: \n";
    int mw;
    mw = m;
    for(i=n; i>0 && maxprice > 0; i--)
    {
        if(maxprice == dp[i-1][mw])
        {
            continue;
        }
        else
        {
            cout<<"("<<w[i]<<","<<p[i]<<"),";
            maxprice = maxprice - p[i];
            mw = mw - w[i];
        }
    }
    cout<<endl;
    return 0;
}

