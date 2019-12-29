#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int dp[100][100];
string x,y;
int m,n,i,j;

int maximum(int a, int b)
{
    return (a>b) ? a : b;
}

int lcs(int m,int n)
{
    if(m==0 || n==0)
      return dp[m][n]=0;
    if(dp[m][n] != -1)
      return dp[m][n];
    if(x[m] == y[n])
    {
        dp[m][n] = lcs(m-1,n-1)+1;
    }
    else
    {
       dp[m][n] = maximum(lcs(m-1,n),lcs(m,n-1));
    }
    return dp[m][n];
}
int main()
{
   cout<<"Enter first sequence: ";
   cin>>x;
   cout<<"Enter second sequence: ";
   cin>>y;
   memset(dp,-1,sizeof(dp));
   m = x.length();
   n = y.length();
   int len = lcs(m,n);
   cout<<"The length of LCS is "<<len<<endl;
   char lc[len+1];
   lc[len] = '\0';
   i = m, j=n;
   while(i>0 && j>0)
   {
       if(x[i-1]==y[j-1])
       {
           lc[len-1] = x[i-1];
           i--,j--,len--;
       }
       else if(dp[i-1][j] > dp[i][j-1])
       {
           i--;
       }
       else
       {
           j--;
       }
   }
   cout<<"Tne longest common sequence is "<<lc<<endl;
   printf("%s",lc);
   return 0;
}

