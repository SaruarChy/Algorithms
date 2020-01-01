#include<bits/stdc++.h>
using namespace std;
struct item
{
    int itemNo;
    double price;
    double weight;
    double ppw;

};
bool cmp(struct item a, struct item b)
{
    return a.ppw > b.ppw;
}
double fractional_knapsack(int capacity, struct item arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        arr[i].ppw = (arr[i].price / arr[i].weight);
    }
    sort(arr, arr+n, cmp);
    cout<<"details of all items after sorting: \n";
    cout<<"itemNo\t"<<"Price\t"<<"Weight\t"<<"PPW\t"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i].itemNo<<"\t"<<arr[i].price<<"\t"<<arr[i].weight<<"\t"<<arr[i].ppw<<endl;
    }
    cout<<endl;
    double totalprice = 0.0;
    for(i=0; i<n ; i++)
    {
        if(arr[i].weight <= capacity)
        {
            totalprice+= arr[i].price;
            capacity = capacity - arr[i].weight;
        }
        else
        {
            totalprice+= (capacity*arr[i].ppw);
            capacity = 0;
        }
    }
    return totalprice;
}
int main()
{
    int i,n,capacity;
    double max;
    struct item arr[50];
    cout<<"Number of items: \n";
    cin>>n;
    cout<<"Capacity of knapsack: \n";
    cin>>capacity;
    cout<<endl;
    cout<<"details of all items: \n";
    cout<<"itemNo\t"<<"Price\t"<<"Weight\t"<<endl;
    for(i=0; i<n; i++)
    {
     cin>>arr[i].itemNo;
     cin>>arr[i].price;
     cin>>arr[i].weight;
     cout<<endl;
    }
    cout<<endl;
    max = fractional_knapsack(capacity,arr,n);
    cout<<"Total price"<<max;
    return 0;

}
