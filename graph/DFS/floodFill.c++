#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char grid[100][100];
bool vis[100][100];
int n, m;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid (int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void dfs(int curx, int cury)
{
    vis[curx][cury] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if (valid(nx, ny) && grid[nx][ny] == '.' && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
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