#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
* The graph must be DAG
* We cab solve it using DFS or BFS
*/
const int N = 1e5 + 2;

vector <int> graph[N];
vector <int> topologyDFS, topologyBFS;
vector<bool> visited(N, false);
int InDegree[N];

void DFS (int node)
{
    visited[node] = 1;
    for (auto child : graph[node])
    {
        if (!visited [child])
        {
            DFS (child);
        }
    }
    topologyDFS.push_back(node); // Nodes will be added in reverse order
}

void BFS(int n)
{
    // ge the min TOPO sort [u can change to the max]
    priority_queue<int, vector<int>, greater<int>> q; 
    for (int i = 1; i <= n; i++)
        if (!InDegree[i])
            q.push(i);

    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        topologyBFS.push_back(u);
        for (auto v : graph[u])
        {
            InDegree[v]--;
            if (!InDegree[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int m;
    cin >> m;
    cout << "Enter the connection !\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back (v);
        InDegree[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            DFS(i);

    reverse(topologyDFS.begin(), topologyDFS.end());
    if (topologyDFS.size() != n)
    {
        cout << "Can't Use Toplogyical sort\n";
        return 0;
    }
    cout << "Topology Sort DFS : { ";
    for (auto i : topologyDFS)
        cout << i << ' ';
    cout << "}\n";

    visited.assign(N, false);
    BFS(n);
    cout << "Topology Sort BFS : { ";
    for (auto i : topologyBFS)
        cout << i << ' ';
    cout << "}\n";
}
