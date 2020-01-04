#include<iostream>
#include<algorithm>
using namespace std;

int id[1000],nodes, edges;
pair<long long ,pair<int,int> > p[1000];
void initialize()
{
   for(int i=0;i< 1000; i++)
   {
       id[i] = i;
   }
}
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x, int y)
{
    int p =  root(x);
    int q = root(y);
    id[p] = id[q];
}
long long kruskal(pair<long long ,pair<int,int> > p[])
{
    int x,y;
    long long cost, minCost=0;
    for(int i=0; i<edges;i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!= root(y))
        {
            minCost +=cost;
            union1(x,y);
        }
    }
    return minCost;
}
int main()
{
    int x,y;
    long long weight, minimumCost;
    initialize();
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        p[i] = make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    minimumCost = kruskal(p);
    cout<<minimumCost<<endl;
    return 0;
}
/*
9 14
4 6 14
3 6 4
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
9 7 6
9 8 7
1 8 8
2 8 11
3 9 2
*/
