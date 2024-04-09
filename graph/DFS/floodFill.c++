#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

char grid[100][100];
bool vis[100][100];
int n, m;

bool in (int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void dfs (int i, int j)
{
    vis[i][j] = 1;
    if (grid[i][j] == '.' && !vis[i][j] && in (i, j))
    {
        dfs (i, j + 1);
        dfs (i, j - 1);
        dfs (i + 1, j);
        dfs (i - 1, j);
    }
    return;
}

int main (void)
{
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) 
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs (i, j);
            }
        }
    }
    cout << ans << '\n';  
} 