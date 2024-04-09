#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

vector <int> graph[N];
bool visited[N], instack [N];

bool dfs (int node)
{
    visited[node] = 1;
    instack[node] = 1;
    for (auto child : graph[node])
    {
        if (!visited[child])
            if (dfs (child))
                return true;
        // because it visited and the node in the stack
        else if (instack[child])
            return true;
    }
    instack[node] = 0;
    return false;
}

bool dfsDir (int node, int p)
{
    visited[node] = 1;
    for (auto child : graph[node])
    {
        if (!visited[child])
        {
            if (dfsDir (child, node))
                return 1;
        }
        else if (child != p)
            return 1;
    }
    return 0;
}

int main (void)
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int m;
    cin >> m;
    cout << "Enter the conection !\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back (v);
        graph[v].push_back (u); // undirected graph
    }
    (dfs (1)) ? cout << "Cycle !\n" : cout << "Not Cycle !\n";
    (dfsDir (1, -1)) ? cout << "Cycle !\n" : cout << "Not Cycle !\n";
} 