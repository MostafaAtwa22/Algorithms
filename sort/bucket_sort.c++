#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

/**
 * Time  : best [O(N)], worst [O(N^2) => O(NlogN)]
 * Space : O(N)
*/

const int N = 1e5;
vector<long double> bucket[N];

void bucketSort(vector<long double> & a, long MinElement, int MaxElement)
{
    int j = 0;
    for (int i = MinElement; i <= MaxElement; i++)
    {
        if (bucket[i].empty())
            continue;
        sort(bucket[i].begin(), bucket[i].end());
        for (auto b : bucket[i])
            a[j++] = b;
    }
}

void print(vector<long double> & a)
{
    cout << "Array : [ ";
    for (auto i : a)
        cout << i << ' ';
    cout << "]\n";
}

int main()
{
    int n;
    int MaxElement = INT_MIN;
    int MinEleemnt = INT_MAX;
    cout << "Enter the size : ";
    cin >> n;
    vector<long double> a(n);
    cout << "Enter the array Elements !!\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int ind = a[i] * n;
        bucket[ind].push_back(a[i]);
        MaxElement = max(MaxElement, ind);
        MinEleemnt = min(MinEleemnt, ind);
    }
    bucketSort(a, MinEleemnt, MaxElement);
    print(a);
}