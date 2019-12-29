#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[100][100];
int s[100][100];
int MCM(int arr[], int i, int j)
{
    int k;
    int q;
    if(i == j)
    return dp[i][j]=0;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int minV = INT_MAX;
    for(k=i; k<=j-1; k++)
    {
        q = MCM(arr,i,k) + MCM(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];

        if(q < minV)
        {
            minV = q;
        }
        dp[i][j] = minV;
        s[i][j] = k;
    }
    return dp[i][j];
}
int printoptimalparen(int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i+1;
    }
    else
    {
        cout<<"(";
        printoptimalparen(i,s[i][j]);
        printoptimalparen(s[i][j]+1, j);
        cout<<")";
    }
}
int main()
{
    int n,i;
    cout<<"Enter number of matrices\n";
    cin>>n;
    n++;
    int arr[n+1];
    cout<<"Enter dimensions\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<"Minimum number of multiplication is: "<<MCM(arr,1,n-1);
    cout <<endl;
    cout<<"Chain Order: ";
    printoptimalparen(0,n-2);
    return 0;
}


