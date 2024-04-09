#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 2;
vector <int> graph[N];
int matrix[N][N];

int main()
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int m;
    cin >> m;
    cout << "Enter the conection !\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back (v);
        graph[v].push_back (u); // undirected graph
        matrix[u][v] = 1;
        matrix[v][u] = 1;       // undirected graph
    }

    cout << "\nAdj List ! \n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : { ";
        for (auto j : graph[i])
            cout << j << ' ';
        cout << "}\n";
    }
    cout << "\nMatrix !\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
