#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <queue>
#define max 101
using namespace std;
int n,e;
/*
 * Returns true if there is a path from source 's' to sink 't' in
 * residual graph. Also fills parent[] to store the path
 */
int bfs(int rGraph[max][max], int s, int t, int parent[])
{
    bool visited[max];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

/*
 *  A DFS based function to find all reachable vertices from s.
 */
void dfs(int rGraph[max][max], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
    }
}

/*
 * Prints the minimum s-t cut
 */
void minCut(int graph[max][max], int s, int t)
{
    int u, v;
    int rGraph[max][max];
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
             rGraph[u][v] = graph[u][v];
    }
    int parent[max];
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    bool visited[max];
    memset(visited, 0, sizeof(visited));
    dfs(rGraph, s, visited);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i] && !visited[j] && graph[i][j])
                cout << i << " - " << j << endl;
        }
    }
    return;
}
/*
 * Main Contains Menu
 */

int main()
{
    int i,u,v,w;
    int s,t;
    int graph[max][max];
    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v>>w;
        graph[u][v] = w;
    }
    cin>>s>>t;
    cout<< "Min cut"<<"\n";
    minCut(graph,s,t);
     cout<< endl;

    return 0;
}

