#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<long long , int> pii;
bool marked[1000];
vector< pii > adj[1000];

long long prim(int x)
{
    priority_queue<pii, vector<pii> , greater<pii> > pq;
    int y;
    long long minimumCost=0;
    pii p;
    pq.push(make_pair(0,x));
    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();
        x = p.second;
        if(marked[x]==true)
          continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i=0; i< adj[x].size();i++)
        {
            y = adj[x][i].second;
            if(marked[y]==false)
             pq.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges,x,y;
    long long weight,minimumCost;
    cout<<"Enter number of nodes and edges\n";
    cin>>nodes>>edges;
    cout<<"Vertex to vertex and its  weight\n";
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));
    }
    minimumCost = prim(1);
    cout<<"Minimum cost is "<<minimumCost<<endl;
    return 0;
}
