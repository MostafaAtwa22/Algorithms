#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include  <algorithm>
using namespace std;

class DSU 
{
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DSU(int V)
    {
        rank.resize(V + 1, 0);
        parent.resize(V + 1, 0);
        size.resize(V + 1, 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u)
    {
        if (parent[u] == u) 
            return u;
        return parent[u] = find(parent[u]);
    }

    void uniteByRank(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    DSU dsu(V);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (dsu.find(u) != dsu.find(v)) { // if u and v are not in the same parent
            dsu.uniteByRank(u, v);
            mstWeight += w;
        }
    }
    cout << mstWeight << endl;
}