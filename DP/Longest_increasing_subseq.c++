#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
 * 2 3 4 3 4 1 5
 * 2 3 4 5 => len = 4
 * we will use also take or leave 
 */

const int N = 1000 + 4, MAXV = 10000 + 4;
int n, a[N];
bool vis[N][MAXV];
int memo[N][MAXV];

int Recersion_SubSeq(int i, int last) // O(2 ^ N)
{
    if (i == n)
        return 0;

    // first => leave
    int ch1 = Recersion_SubSeq(i + 1, last);

    int ch2 = 0;
    // check if the next > last
    if (a[i] > last)
        ch2 = 1 + Recersion_SubSeq(i + 1, a[i]);
    return max(ch1, ch2);
}

int DP_SubSeq(int i, int last) 
{
    if (i == n)
        return 0;

    // memorize the choices 
    if (vis[i][last])
        return memo[i][last];
    vis[i][last] = 1;

    // first => leave
    int ch1 = DP_SubSeq(i + 1, last);
    
    int ch2 = 0;
    // check if the next > last
    if (a[i] > last)
        ch2 = 1 + DP_SubSeq(i + 1, a[i]);
    return memo[i][last] = max(ch1, ch2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Recersion way : " << Recersion_SubSeq(0, -1) << '\n';
    cout << "DP way : " << DP_SubSeq(0, -1) << '\n';
}