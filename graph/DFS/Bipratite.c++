#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

vector <int> graph[N];
int color[N];
vector <int> set1, set2;

bool dfs (int node, int c)
{
    color[node] = c;
    for (auto child : graph[node])
    {
        if (color[node] == color[child])
            return 0;
        if (!color[child])
            if (!dfs (child, -c))
                return 0;
    }
    return 1;
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

    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (!dfs (i, 1))
            {
                cout << "It's not Bipratite!\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
            set1.push_back (i);
        else if (color[i] == -1)
            set2.push_back (i);
    }

    cout << set1.size () << '\n';
    for (auto i : set1)
        cout << i << ' ';
    cout << '\n';

    cout << set2.size () << '\n';
    for (auto i : set2)
        cout << i << ' ';
    cout << '\n';
}