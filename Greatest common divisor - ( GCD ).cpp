#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b;
    cout<<"Enter the numbers to find it's GCD:\n";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a,b);
    cout<<endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

// Driven code
int main()
{
    int arr[] = { 2, 4, 6, 8, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findGCD(arr, n) << endl;
    return 0;
}
*/
/*
96 ...56...14
*/
