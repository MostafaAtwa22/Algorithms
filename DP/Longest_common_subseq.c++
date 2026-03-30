#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3005;
string s, t;
bool vis[N][N];
int memo[N][N];
int n, m;

ll LSC (int i, int j)
{
    if (i == n || j == m)
        return 0;
    
    if (vis[i][j])
        return memo[i][j];
    vis[i][j] = 1;

    ll ch1 = 0;
    if (s[i] == t[j])
        ch1 = 1 + LSC(i + 1, j + 1);

    ll ch2 = LSC(i + 1, j);
    ll ch3 = LSC(i, j + 1);

    return memo[i][j] = max({ch1, ch2, ch3});
}

void Print(int i, int j)
{
    if (i == n || j == m)
        return;

    if (s[i] == t[j])
    {
        cout << s[i];
        Print(i + 1, j + 1);
    }
    else if (memo[i][j] == memo[i][j + 1])
        Print(i, j + 1);
    else
        Print(i + 1, j);
}

int main()
{
    cin >> s >> t;
    n = s.size(), m = t.size();
    LSC(0, 0);
    Print(0, 0);
    cout << endl;
}