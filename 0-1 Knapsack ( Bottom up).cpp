#include<iostream>
using namespace std;

int knapsack(int n,int m,int w[],int p[])
{
    int B[100][100],i,j;
    for(i=0;i<=n;i++)
      B[i][0] = 0;
    for(j=0;j<=m;j++)
      B[0][j] = 0;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(w[i]<=j)
            {
                if((p[i]+B[i-1][j-w[i]]) >= B[i-1][j])
                {
                    B[i][j] = p[i]+B[i-1][j-w[i]];
                }
                else
                {
                    B[i][j] = B[i-1][j];
                }
            }
            else
            {
                B[i][j] = B[i-1][j];
            }
        }
    }
    cout<<"DP Table[i,j]: \n";
    for(i=0;i<=n;i++)
    {
        cout<<i<<"=\t";
        for(j=0;j<=m;j++)
        {
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Selected items are: \n";
    int mw;
    mw = m;
    int maxprice = B[n][m];
    for(i=n; i>0 && maxprice > 0; i--)
    {
        if(maxprice == B[i-1][mw])
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
    return B[n][m];
}


int main()
{
    int i,m,n,maxprice;
    int w[100],p[100];
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack: ";
    cin>>m;
    cout<<"Enter the details of items\n";
    cout<<"Weight Price\n";
    for(i=1;i<=n;i++)
    {
        cin>>w[i]>>p[i];
    }
    maxprice = knapsack(n,m,w,p);
    cout<<"Maximum Profit "<<maxprice<<endl;
    return 0;
}
/*
4
5
2 3
3 4
4 5
5 6
*/

