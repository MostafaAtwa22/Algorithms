#include <bits/stdc++.h>
using namespace std;

// DP => is to save the state of the prev operation

#define ll long long
const int N = 1e5 + 10;
bool vis[N];
ll DP[N];

ll Fib(ll n) // O(N)
{
    if (n <= 2)
        return 1;
    
    if (vis[n])
        return DP[n];
    vis[n] = 1;

    return DP[n] = Fib(n - 1) + Fib(n - 2);
}

int main()
{
    for (int i = 0; i <= 10; i++)
        cout << "Fib " << i << " = " << Fib(i) << '\n';
}