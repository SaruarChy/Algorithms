#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector< int > adj[100];
bool visited[100];
int n,e,u,v,x,y;

void BFS(int source)
{
    int i;
    queue< int > queue;
    memset(visited,false, sizeof(visited));
    queue.push(source);
    visited[source] = 2;
    while(!queue.empty())
    {
        u = queue.front();
        queue.pop();
        cout<<u<<"->";
        visited[u] = true;
        for(i=0;i< adj[u].size();i++)
        {
            v = adj[u][i];
            if(visited[v]==false)
            {
                queue.push(v);
                visited[v] = 2;
            }
        }
    }
}
int main()
{
    int source;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;
    memset(adj,false,sizeof(adj));
    cout<<"Enter vertex to vertex"<<endl;
    while(e--)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Enter the source to start the BFS traversal: ";
    cin>>source;
    BFS(source);
    return 0;
}

