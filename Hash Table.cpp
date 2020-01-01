#include<iostream>
#include<limits.h>
using namespace std;

void Insert(int arr[],int hfn,int size)
{
    int element, pos, n=0;
    cout<<"Enter key element to insert\n";
    cin>>element;
    pos = element%hfn;

    while(arr[pos] != INT_MIN)
    {
        if(arr[pos]==INT_MAX)
          break;
        pos = (pos+1)%hfn;
        n++;
        if(n==size)
          break;
    }
    if(n==size)
    {
        cout<<"Hash table was full of elements\nNo placce to insert this elements\n\n";
    }
    else
    {
        arr[pos] = element;
    }
}
void Delete(int arr[],int hfn, int size)
{
    int element, n=0,pos;
    cout<<"Enter element to delete\n";
    cin>>element;
    pos = element%hfn;

    while(n++ != size)
    {
        if(arr[pos]==INT_MIN)
        {
            cout<<"Element not found in hash table\n";
            break;
        }
        else if(arr[pos]==element)
        {
            arr[pos] = INT_MAX;
            cout<<"Element deleted\n";
            break;
        }
        else
        {
            pos = (pos+1)%hfn;
        }
    }
    if(--n == size)
    {
        cout<<"Element not found in hash table\n";
    }
    return;
}

void Search(int arr[],int hfn, int size)
{
    int element, pos, n=0;
    cout<<"Enter element to search\n";
    cin>>element;
    pos = element % hfn;

    while(n++ != size)
    {
        if(arr[pos]==element)
        {
            cout<<"Element found at index "<<pos<<endl;
            break;
        }
        else
        {
            if(arr[pos]==INT_MAX || arr[pos]!=INT_MIN)
            {
                pos = (pos+1)%hfn;
            }
        }
    }
    if(--n==size)
    {
        cout<<"Element not found in hash table\n";
    }
    return;
}

void display(int arr[],int size)
{
    int i;
    cout<<"Index\tvalue\n";

    for(i=0;i<size;i++)
    {
        cout<<i<<"\t"<<arr[i]<<"\n";
    }
    return;
}
int main()
{
    int size, hfn,i,choice;

    cout<<"Enter size of hash table: \n";
    cin>>size;

    int arr[size];
    cout<<"Enter hash function [if mod 10 enter 10]\n";
    cin>>hfn;
    for(i=0;i<size;i++)
    {
        arr[i] = INT_MIN;
    }

    do{
      cout<<"Enter your choise\n";
      cout<<"1-> Insert\n 2-> Delete\n 3-> Searching\n 4-> Display\n 0-> Exit\n";
      cin>>choice;

      switch(choice)
      {
          case 1:
            Insert(arr,hfn,size);
            break;
          case 2:
            Delete(arr,hfn,size);
            break;
          case 3:
            Search(arr,hfn,size);
            break;
          case 4:
             display(arr,size);
             break;
          default:
            cout<<"Wrong choice\n";
            break;
      }
    }while(choice);

    return 0;
}

