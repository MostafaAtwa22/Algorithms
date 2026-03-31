#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include  <algorithm>
using namespace std;

/*
flody warshall: find the sortest path between all pairs of vertices.
Time complexity: O(V^3)
Space complexity: O(V^2)
*/
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
} 