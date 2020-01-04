#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>

#define pp pair<int,int>
using namespace std;

struct Edge
{
    int source , dest, weight;
};
void printPath(vector<int> const &parent,int j)
{
    if(j<0)
      return;
    printPath(parent,parent[j]);
    cout<<j<<" ";
}
void bellmanford(vector<Edge> const &edges, int n,int source)
{
    int i,j,u,v,w,k;
    int E = edges.size();
    vector<int> dis(n,INT_MAX);
    vector<int>parent(n,-1);

    dis[source] = 0;
    k = n;
    while(--k)
    {
       for(j=0;j<E;j++)
       {
           u = edges[j].source;
           v = edges[j].dest;
           w = edges[j].weight;
           if(dis[u] != INT_MAX && dis[u]+w < dis[v])
           {
               dis[v] = dis[u]+w;
               parent[v] = u;
           }
       }
    }
    for(j=0;j<E;j++)
       {
           u = edges[j].source;
           v = edges[j].dest;
           w = edges[j].weight;
           if(dis[u] != INT_MAX && dis[u]+w < dis[v])
           {
               cout<<"Negative weight cycle found!!";
               return;
           }
       }
       for(i=1;i<=n;i++)
       {
           cout<<"Distance of vertex "<<i<<"from the source is "<<dis[i]<<". It's path is [";
           printPath(parent,i);
           cout<<"]"<<"\n";
       }


}

int main()
{
    int n,e,source,i;
    int u,v,w;
    cout<<"Enter number of nodes and edges: \n";
    cin>>n>>e;
    vector <Edge> edges;
    cout<<"Vertex to vertex and its edges: \n";

    for(i=0;i<e;i++)
    {
        edges.push_back(Edge());
        cin>>u>>v>>w;
        edges[i].source = u;
        edges[i].dest = v;
        edges[i].weight =w;
    }
    cout<<"Enter the starting node: ";
    cin>>source;
    bellmanford(edges,n,source);
    return 0;
}
 /*6 8
1 2 6
1 3 10
2 4 1
4 3 -4
3 5 2
4 5 -1
5 6 -2
6 3 1
*/


