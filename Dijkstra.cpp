#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

#define pp pair<int,int>
using namespace std;
int dis[100];
int parent[100];

struct node
{
    bool operator()(const pair<int,int>&p1, const pair<int,int>&p2)
    {
        return p1.second < p2.second;
    }
};
vector<pp> adj[100];

void printPath(int parent[],int j)
{
    if(parent[j] == -1)
       return;
    printPath(parent,parent[j]);
    cout<<j<<"->";
}
void dijkstra(int n,int source)
{
    int u,v,w,i;
    priority_queue<pp, vector<pp>,node> pq;
    memset(dis,100,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    dis[source] = 0;
    pq.push(pp(source,dis[source]));
    while(!pq.empty())
    {
        u = pq.top().first;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            v = adj[u][i].first;
            w = adj[u][i].second;
            if(dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pq.push(pp(v,dis[v]));
                parent[v]=u;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<"Vertex "<<i<<" "<<"Minimum distance = "<<dis[i]<<" path "<<source<<"->";
        printPath(parent,i);
        cout<<endl;
    }
    return;
}

int main()
{
    int n,e,source,i;
    int u,v,w;
    cout<<"Enter number of nodes and edges: "<<endl;
    cin>>n>>e;
    cout<<"vertex to vertex and its weight: \n";
    while(e--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(pp(v,w));
        adj[v].push_back(pp(u,w));
    }
    cout<<"Enter the starting node: ";
    cin>>source;
    dijkstra(n,source);
    return 0;
}

