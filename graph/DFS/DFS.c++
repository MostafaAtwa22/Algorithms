#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

vector <int> graph[N];
vector <int> path;
bool visit[N];
int parent[N];
int depth[N];
int degree[N];

void dfs (int node)
{
    visit[node] = 1;
    for (auto child : graph[node])
    {
        if (!visit[child])
        {
            parent[child] = node;
            depth[child] = depth[node] + 1;
            dfs (child);
        }
    }
}

void build_path (int from, int to)
{
    for (int node = to; node != from; node = parent[node])
        path.push_back (node);
    path.push_back (from);
    reverse (path.begin (), path.end ());
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
        graph[v].push_back (u); // undirected graph
        degree[u]++, degree[v]++;
    }

    cout << "The # of connected components int the graph : ";
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            counter++;
            dfs (i);
        }
    }
    cout << counter << '\n';

    cout << "The parents ! \n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << parent[i] << '\n';

    cout << "Depth for each node !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << depth[i] + 1 << '\n';

    cout << "Degree for each node !\n";
    for (int i = 1; i <= n; i++)
        cout << i << " : " << degree[i] << '\n';

    cout << "Enter from : ";
    int from;
    cin >> from;
    cout << "Enter to : ";
    int to;
    cin >> to;
    build_path (from, to);
    cout << "Path : ";
    for (auto i : path)
        cout << i << ' ';
    cout << endl;
}
