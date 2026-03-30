#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 4;
string s, t;
bool vis[N][N];
int memo[N][N];

int LSC (int i, int j)
{
    if (i == s.size() || j == t.size())
        return 0;
    
    if (vis[i][j])
        return memo[i][j];
    vis[i][j] = 1;

    int ch1 = 0;
    if (s[i] == t[j])
        ch1 = 1 + LSC(i + 1, j + 1);
    
    int ch2 = LSC(i + 1, j);
    int ch3 = LSC(i, j + 1);

    return memo[i][j] = max({ch1, ch2, ch3});
}

void Print(int i, int j)
{
    if (i == s.size() || j == t.size())
        return;
    
    int ret = memo[i][j];
    if (s[i] == s[j])
    {
        if (ret == LSC(i + 1, j + 1) + 1) // O(1)
        {
            cout << s[i];
            Print(i + 1, j + 1);
            return;
        }
    }
    else 
    {
        if (ret == LSC(i, j + 1))
        {
            Print(i, j + 1);
            return;
        }
        if (ret == LSC(i + 1, j))
        {
            Print(i + 1, j);
            return;
        }
    }
}

int main()
{
    cin >> s >> t;
    cout << LSC(0, 0) << '\n';
    Print(0, 0);
    cout << endl;
}