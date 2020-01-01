#include<iostream>
#include<math.h>
#define SIZE 1000000
using namespace std;
long p[SIZE],pvalues[SIZE], n;
long list[SIZE];
long listsize;

void prime(void)
{
    long i,j;
    p[0] = 1;
    p[1] = 1;
    for(i=2; i<= sqrt(SIZE);i++)
    {
        if(p[i]==0)
        {
            for(j=i*i; j <= SIZE; j+=i)
            {
                p[j] = 1;
            }
        }
    }
    j=0;
    for(i=0;i<=SIZE;i++)
    {
        if(p[i]==0)
        {
            pvalues[j++]=i;
        }
    }
    return;
}

void primeFactorize(long n)
{
    listsize = 0;
    long sqrtn = long (sqrt(n));
    for(long i=0; pvalues[i]<= sqrtn; i++)
    {
        if(n % pvalues[i] == 0)
        {
            while(n % pvalues[i]==0)
            {
                n/= pvalues[i];
                list[listsize] = pvalues[i];
                listsize++;
            }
        }
    }
    if(n > 1)
    {
        list[listsize] = n;
        listsize++;
    }
}

int main()
{
    prime();
    cout<<"Enter the number to factorize: ";
    cin>>n;
    if(n==1){
     cout<<"1=1"<<endl;
    }
    else if(n == -1){
     cout<<"-1 = -1 x 1"<<endl;
    }
    else
    {
        primeFactorize(n);
    }
    cout<<"The number"<<n<<"has the following factors :\n";
    for(long i=0; i< listsize;i++)
    {
        cout<<list[i]<<"\t";
    }
    cout<<endl;
    return 0;
}

