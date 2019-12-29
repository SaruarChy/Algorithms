#include<iostream>
#include<string>
using namespace std;
int i,j,m,n,c[20][20],b[20][20];
string x,y;

void print(int i,int j)
{
    if(i==0 || j==0)
      return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]=='u')
    {
        print(i-1,j);
    }
    else
    {
        print(i,j-1);
    }

}
void lcs()
{
   m = x.length();
   n = y.length();
   for(i=0;i<=m;i++)
     c[i][0] = 0;
   for(i=0;i<=n;i++)
     c[0][i] = 0;

   for(i=1;i<=m;i++)
   {
       for(j=1;j<=n;j++)
       {
           if(x[i-1]==y[j-1])
           {
               c[i][j] = c[i-1][j-1]+1;
               b[i][j] = 'c';
           }
           else if(c[i-1][j] >=c[i][j-1])
           {
               c[i][j] = c[i-1][j];
               b[i][j] = 'u';
           }
           else
           {
               c[i][j] = c[i][j-1];
               b[i][j] = 'l';
           }
       }
   }
}
int main()
{
    cout<<"Enter first string: ";
    cin>>x;
    cout<<"Enter second string: ";
    cin>>y;
    cout<<"The longest common sequence is ";
    lcs();
    print(m,n);
    cout<<endl;
    cout<<"The length of lcs is "<<c[m][n]<<endl;
    return 0;
}
