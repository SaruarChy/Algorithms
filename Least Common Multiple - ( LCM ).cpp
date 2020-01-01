#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}
int lcm(int a, int b)
{
   return (a*b)/ gcd(a,b);
}

int main()
{
    int a,b;
    cout<<"Enter the numbers to find it's LCM:\n";
    cin>>a>>b;
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<lcm(a,b);
    cout<<endl;
    return 0;
}

