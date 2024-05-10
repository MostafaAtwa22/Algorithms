#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp (pair<int, pair<int, string>>& L, pair<int, pair<int, string>>& R)
{
    if (L.first == R.first)
        return L.second.first < R.second.first;
    return L.first > R.first;
}

void Sequance (string name[], int profite[], int deadline[], int size)
{
    vector <pair<int, pair<int, string>>> MaxProfiteJobs;
    int MaxDeadLine = 0;
    for (int i = 0; i < size; i++)
    {
        MaxProfiteJobs.push_back({profite[i], {deadline[i], name[i]}});
        MaxDeadLine = max(MaxDeadLine, deadline[i]);
    }

    sort(MaxProfiteJobs.begin(), MaxProfiteJobs.end(), cmp);
    cout << "\nThe Sorted Jobs depends on Profite !!\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Job #" << i + 1 << " : " << MaxProfiteJobs[i].second.second << ", ";
        cout << MaxProfiteJobs[i].first << ", " << MaxProfiteJobs[i].second.first << '\n';
    }

    int cnt[MaxDeadLine + 1] = {};
    int MaxProftiesSum = 0;
    vector<int> Maxprofites;
    vector<string> JobsWithMaxProfite;
    for (int i = 0; i < size; i++)
    {
        for (int j = MaxProfiteJobs[i].second.first; j > 0; j--)
        {
            if (cnt[j] == 0)
            {
                cnt[j]++;
                MaxProftiesSum += MaxProfiteJobs[i].first;
                Maxprofites.push_back(MaxProfiteJobs[i].first);
                JobsWithMaxProfite.push_back(MaxProfiteJobs[i].second.second);
                break;
            }
        }
    }
    cout << "\nMax Profite sum = " << MaxProftiesSum << '\n';
    cout << "\nThe Selected Jobs With Max profite !!\n";
    for (int i = 0; i < JobsWithMaxProfite.size(); i++)
    {
        cout << "Job #" << i + 1 << " : ";
        cout << JobsWithMaxProfite[i] << " => " << Maxprofites[i] << '\n';
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the number of Jobs : ";
    cin >> size;
    string name[size];
    int profite[size];
    int deadline[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Job #" << i + 1 << " Name : ";
        cin >> name[i];
        cout << "Enter the Job #" << i + 1 << " profite : ";
        cin >> profite[i];
        cout << "Enter the Job #" << i + 1 << " deadline : ";
        cin >> deadline[i];
        cout << "-------------------------------------------\n";
    }
    Sequance(name, profite, deadline, size);
}