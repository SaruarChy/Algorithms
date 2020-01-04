#include<iostream>
#include<queue>
#include<cstring>
#include<climits>
#define max 101
using namespace std;
int n,e;

bool bfs(int rg[max][max],int s,int t,int par[])
{
    bool visit[max];
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(s);
    visit[s] = true;
    par[s] = -1;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for(int b=0; b<n;b++)
        {
            if(visit[b]==false && rg[a][b]>0)
            {
                q.push(b);
                par[b] = a;
                visit[b]=true;
            }
        }
    }
    return (visit[t]==true);
}
int fordfulkerson(int g[max][max],int n,int s,int t)
{
    int u,v;
    int rg[max][max];
    for(u=0;u<n;u++)
    {
        for(v=0;v<n;v++)
        {
            rg[u][v]=g[u][v];
        }
    }
    int par[max];
    int maxflow=0;
    while(bfs(rg,s,t,par))
    {
        int pathflow = INT_MAX;
        for(v=t; v!=s; v=par[v])
        {
            u = par[v];
            pathflow = min(pathflow,rg[u][v]);
        }
        for(v=t; v!=s; v=par[v])
        {
            u = par[v];
            rg[u][v] -= pathflow;
            rg[v][u] +=pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
int main()
{
    int i,u,v,w;
    int s,t;
    int g[max][max];
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g[u][v] = w;
    }
    cin>>s>>t;
    cout<<"Max flow in this graph is: "<<fordfulkerson(g,n,s,t)<<endl;
    return 0;
}



/*6 9
0 1 16
1 3 12
3 5 20
0 2 13
3 2 9
2 1 4
2 4 14
4 5 4
4 3 7
0 5
*/

