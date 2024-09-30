#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

vector <int> graph[N];
bool visitedUnDir[N];
int visitedDir[N];

bool dfsDir (int node)
{
    visitedDir[node] = 1;
    bool res = false;
    for (auto child : graph[node])
    {
        if (visitedDir[child] == 1) // visit it and there is a loop
            return true;
        else if (visitedDir[child] == 0) // it's not visited yet
            res |= dfsDir(child);
    }
    visitedDir[node] = 2; // visit and finish the DFS of it
    return res;
}

bool dfsUnDir (int node, int p)
{
    visitedUnDir[node] = 1;
    bool res = false;
    for (auto child : graph[node])
    {
        if (child == p)
            continue;
        if (visitedUnDir[child])
            return true;
        else
            res |= dfsUnDir(child, node);
    }
    return res;
}

int main ()
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
    (dfsDir (1)) ? cout << "Cycle !\n" : cout << "Not Cycle !\n";
    (dfsUnDir (1, -1)) ? cout << "Cycle !\n" : cout << "Not Cycle !\n";
} 