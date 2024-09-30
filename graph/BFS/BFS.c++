#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include  <algorithm>
using namespace std;
/*
* go for every node level by level
* use to find the shortest path between 2 nodes
* u can use it to print the tree using level order traversal 
*/
const int N = 1e5;
vector <int> g[N];
bool vis[N];
int parent[N] = {-1};
int Depth[N] = {-1};

void BFS (int node) 
{
    queue <int> q;
    q.push (node);
    vis[node] = 1;
    Depth[node] = 0;
    while (!q.empty ())
    {
        int front = q.front ();
        q.pop ();
        cout << front << ' ';
        for (auto child : g[front])
        {
            if (!vis[child]) 
            {
                q.push(child);
                vis[child] = true;
                parent[child] = front;
                Depth[child] = Depth[front] + 1;
            }
        } 
    }
}

void print_Paht (int from, int to)
{
    stack<int> path;
    int cur = to;
    while (cur != from)
    {
        path.push(cur);
        cur = parent[cur];
    }
    while(!path.empty()) 
    {
        cout << path.top() << " ";
        path.pop(); 
    }
    cout << '\n';
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

    BFS (1);

    cout << "\nParent of each node !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << parent[i] << '\n';

    cout << "Depth of nodes !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << Depth[i] << '\n';
}