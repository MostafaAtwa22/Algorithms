#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void algorithm (string id[] , int profits[] , int deadlines[] , int n)
{
    pair <pair <int , int> , string> jobs[n];
    for (int i = 0; i < n; i++)
    {
        jobs[i].first.first = profits[i];
        jobs[i].first.second = deadlines[i];
        jobs[i].second = id[i];
    }
    sort (jobs , jobs + n);
    vector <pair <int , string>> sequance (n + 1 , {0 , "a"});
    int sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = jobs[i].first.second; j > 0; j--)
        {
            if (sequance[j].first == 0)
            {
                sequance[j].first = jobs[i].first.first;
                sequance[j].second = jobs[i].second;
                sum += jobs[i].first.first;
                break;
            }
        }
    }
    cout << "The optimal solution = " << sum << '\n';
    cout << "The sequance of solution !!\n";
        for (auto i : sequance)
            if (i.first != 0)
                cout << i.first << " - " << i.second << '\n';
}

int main (void)
{
    cout << "Enter the number of tasks : ";
    int n;
    cin >> n;

    cout << "Enter the ID of tasks !\n";
    string id[n];
    for (auto &i : id)
        cin >> i;

    cout << "Enter the profits of tasks !\n";
    int profits[n];
    for (auto &i : profits)
        cin >> i;

    cout << "Enter the deadlines of tasks !\n";
    int deadlines[n];
    for (auto &i : deadlines)
        cin >> i;
    algorithm (id , profits , deadlines , n);
}