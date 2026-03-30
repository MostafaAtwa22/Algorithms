#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100 + 5, MAXW = 1e5 + 4; 
int n, maxWeight;
int weight[N], value[N];
bool vis[N][MAXW];
ll memo[N][MAXW];

ll CompleteSearch (int ind, int rem) // Slow O(2 ^ n)
{
    if (ind == n)
        return 0;
    // choise 1 => leave the element
    ll ch1 = CompleteSearch(ind + 1, rem);

    ll ch2 = 0;
    // choise 2 => take the element
    if (rem >= weight[ind])
        ch2 = value[ind] + CompleteSearch(ind + 1, rem - weight[ind]);

    return max(ch1, ch2);
}

ll DP (int ind, int rem) // faster O(N * Max Weight)
{
    if (ind == n)
        return 0;

    // if u save it before ret urn the value
    if (vis[ind][rem])
        return memo[ind][rem];
    vis[ind][rem] = 1;

    // choise 1 => leave the element
    ll ch1 = DP(ind + 1, rem);

    ll ch2 = 0;
    // choise 2 => take the element
    if (rem >= weight[ind])
        ch2 = value[ind] + DP(ind + 1, rem - weight[ind]);

    return memo[ind][rem] = max(ch1, ch2);
}

int main()
{
    cin >> n >> maxWeight;
    for (int i = 0; i < n; i++) 
        cin >> weight[i] >> value[i];

    cout << "Complete Search = " << CompleteSearch(0, maxWeight) << '\n';
    cout << "DP = " << DP(0, maxWeight) << '\n';
}