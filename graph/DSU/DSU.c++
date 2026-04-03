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
    
    void uniteBySize(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    DSU dsu(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        dsu.uniteByRank(u, v);
    }

    for (int i = 0; i < V; i++) {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dsu.find(u) == dsu.find(v)) {
            cout << "Same set" << endl;
        } else {
            cout << "Different set" << endl;
        }
    }
}