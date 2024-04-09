#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
* go for every node level by level
* use to find the shortest path between 2 nodes
*/
const int N = 1e5;
vector <int> g[N];
bool vis[N];
int parent[N];
int Depth[N];

void bfs (int node) 
{
    queue <int> q;
    q.push (node);
    vis[node] = 1;
    while (!q.empty ())
    {
        int f = q.front ();
        q.pop ();
        for (auto child : g[f])
        {
            if (!vis[child]) 
            {
                q.push(child);
                vis[child] = true;
                parent[child] = f;
                Depth[child] = Depth[f] + 1;
            }
        }
    }
}

int main () 
{
    int n, m;
    cout << "Enter the # of nodes : ";
    cin >> n;
    cout << "Enter the # of edges : ";
    cin >> m;
    cout << "Enter the conections !\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    bfs (1);
    cout << "Parent of each node !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << parent[i] << '\n';
    cout << "Depth of nodes !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << Depth[i] << '\n';
}