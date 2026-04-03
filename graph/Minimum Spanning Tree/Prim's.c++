#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include  <algorithm>
using namespace std;

/*
Minimum Spanning Tree (MST) : Tree with N nodes & n - 1 edges 
 & all nodes are reachable from eachother (Connected graph)
 & the sum of weights of edges is minimum
 Time: O(E log E)
*/

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    int mst_weight = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        mst_weight += w;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    cout << mst_weight << endl;
}