#include<bits/stdc++.h>
using namespace std;
long long graph[100][100];



void  warshar(int node)
{
    int k,i,j;
    for(k=1;k<=node;k++){
        for(i=1;i<=node;i++){
            for(j=1;j<=node;j++){
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

void print(int n)
{

    cout<<"All pair shortest path are : "<<endl;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int i,j,e,n,u,v,w;

    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INT_MAX;
            }
        }
    }

    cout<<"Enter the number of node and edges :";

    cin>>n>>e;

    while(e--){
        cin>>u>>v>>w;
        graph[u][v]=w;
    }

    warshar(n);
    print(n);

}

/* 5 9

5 1 1
1 2 5
5 2 3
1 4 2
3 1 3
3 5 7
4 3 4
2 3 2
4 5 1
*/

