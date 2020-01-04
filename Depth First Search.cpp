#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
vector< int > adj[100];
bool visited[100];
int n,e,u,v,x,y;

void DFS(int source)
{
    int i;
    stack <int> stack;
    memset(visited,false,sizeof(visited));
    stack.push(source);
    while(!stack.empty())
    {
        u = stack.top();
        cout<<u<<"->";
        stack.pop();
        visited[u] = true;
        for(i=0; i< adj[u].size();i++)
        {
            v = adj[u][i];
            if(visited[v]==false)
            {
                stack.push(v);
                visited[v] = 2;
            }
        }
    }
    return;
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
    cout<<"Enter the source to start the DFS traversal: ";
    cin>>source;
    DFS(source);
    return 0;
}
