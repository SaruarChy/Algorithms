#include<iostream>
#include<algorithm>
using namespace std;
struct activity
{
    int start;
    int finish;
};
bool activitycmp(activity s1, activity s2)
{
    return (s1.finish < s2.finish);
}
void activity_selection(activity arr[],int n)
{
    int i,j;
    sort(arr,arr+n,activitycmp);
    cout<<"After sorted\n";
    for(i=0;i<n;i++)
    {
        cout<<"("<<arr[i].start<<","<<arr[i].finish<<"),";
    }
    cout<<endl;
    i=0;
    cout<<"Following activities are selected\n";
    cout<<"("<<arr[i].start<<","<<arr[i].finish<<"),";
    for(j=1; j<n;j++)
    {
        if(arr[j].start >= arr[i].finish)
        {
            cout<<"("<<arr[j].start<<","<<arr[j].finish<<"),";
            i=j;
        }
    }
    return;
}
int main()
{
    activity arr[100];
    int n,i;
    cout<<"Number of activities : ";
    cin>>n;
    cout<<"Start time and Finish time\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i].start>>arr[i].finish;
    }
    cout<<endl;
    activity_selection(arr,n);
    return 0;
}
