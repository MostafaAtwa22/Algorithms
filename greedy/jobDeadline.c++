#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

/* in this problem we have some jobs and it's deadling that can be done on it and we need to make the max profit */
/* problem link (explaining) :  https://youtu.be/zPtI8q9gvX8 */
int main(void)
{
    int n;
    cout << "Enter the number of jobs : ";
    cin >> n;
    pair <int, pair <int, string>> jobs[n];
    cout << "Enter the jobs name !\n";
    for (int i = 0; i < n; i++)
        cin >> jobs[i].second.second;
    cout << "Enter the jobs profit !\n";
    for (int i = 0; i < n; i++)
        cin >> jobs[i].first;
    int max_deadline = 0;
    cout << "Enter the jobs deadline !\n";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].second.first;
        max_deadline = max (max_deadline, jobs[i].second.first);
    }
    
    // to but on it the visted deadline
    vector <bool> visted (max_deadline + 1, 0);
    // to but on it the jobs that been done
    vector <string> Done;
    // we sort the jobs assume to it's max profit
    sort (jobs, jobs + n);
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (visted[jobs[i].second.first] == 0)
        {
            visted[jobs[i].second.first] = 1;
            ans += jobs[i].first;
            Done.push_back (jobs[i].second.second);
        }
        else
        {
            for (int j = jobs[i].second.first - 1; j > 0; j--)
            {
                if (visted[j] == 0)
                {
                    visted[j] = 1;
                    ans += jobs[i].first;
                    Done.push_back (jobs[i].second.second);
                    break;
                }
            }
        }
    }

    cout << "The jobs that done [ ";
    for (auto i : Done)
        cout << i << ' ';
    cout << "]\n";
    cout << "The max profits sum = " << ans << '\n';
}