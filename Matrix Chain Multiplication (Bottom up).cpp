#include<iostream>
#include<limits.h>
using namespace std;
int m[100][100];
int s[100][100];
int MCM(int arr[],int n)
{
    int i,j,k,l,q;
    for(i=1;i<n;i++){
      m[i][i] = 0;
    }
    for(l=2; l<n ; l++)
    {
        for(i=1; i<n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n-1];
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
    cout<<"Minimum number of multiplication is: "<<MCM(arr,n);
    cout <<endl;
    cout<<"Chain Order: ";
    printoptimalparen(0,n-2);
    return 0;
}
