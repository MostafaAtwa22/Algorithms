#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include  <algorithm>
using namespace std;

/*
Bellman-Ford Algorithm: find the sortest path with negative weight edge, but no negative weight cycle.
work only with directed graph, but can be modified to work with undirected graph by adding two directed edges for each undirected edge.
Time complexity: O(V*E)
*/
int main () 
{
    int V, E;
    cin >> V >> E;
    vector<tuple<int, int, int>> edges; // (u, v, w)
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); 
    }
    vector<int> dist(V, INT_MAX);
    int src;
    cin >> src;
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Check for negative weight cycle
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return 0;   
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "No path from source to vertex " << i << endl;
        } else {
            cout << "Shortest distance from source to vertex " << i << " is " << dist[i] << endl;
        }
    }
    return 0;
}