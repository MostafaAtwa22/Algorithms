#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> g, g2;
    vector<char> vis;
    stack<int> st;

    void dfs1(int u) {
        vis[u] = 1;
        for (int v : g[u])
            if (!vis[v])
                dfs1(v);
        st.push(u);
    }

    void dfs2(int u) {
        vis[u] = 1;
        for (int v : g2[u])
            if (!vis[v])
                dfs2(v);
    }

    int kosaraju(vector<vector<int>>& a) {
        int n = static_cast<int>(a.size());

        g.assign(n, {});
        g2.assign(n, {});
        vis.assign(n, 0);
        while (!st.empty()) st.pop();

        // build graph
        for (int i = 0; i < n; i++) {
            for (int j : a[i]) {
                g[i].push_back(j);
                g2[j].push_back(i);
            }
        }

        // first DFS
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs1(i);

        vis.assign(n, 0);
        int cnt = 0;

        // second DFS
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (!vis[u]) {
                cnt++;
                dfs2(u);
            }
        }

        return cnt;
    }
};

void runTests() {
    Solution sol;

    // One SCC: 0 -> 1 -> 2 -> 0
    vector<vector<int>> g1 = {
        {1},
        {2},
        {0}
    };
    assert(sol.kosaraju(g1) == 1);

    // Three SCCs: {0,1,2}, {3}, {4}
    vector<vector<int>> g2 = {
        {1},
        {2},
        {0, 3},
        {4},
        {}
    };
    assert(sol.kosaraju(g2) == 3);

    // Four isolated nodes -> 4 SCCs
    vector<vector<int>> g3 = {
        {}, {}, {}, {}
    };
    assert(sol.kosaraju(g3) == 4);

    // Empty graph
    vector<vector<int>> g4;
    assert(sol.kosaraju(g4) == 0);
}

int main() {
    runTests();
    cout << "All Kosaraju tests passed.\n";
    return 0;
}
