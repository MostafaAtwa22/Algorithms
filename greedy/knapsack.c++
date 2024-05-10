#include <iostream> 
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp (pair<float, pair<int, int>> & L, pair<float, pair<int, int>> & R)
{
    if (L.first == R.first && L.second.first == R.second.first)
        return L.second.second < R.second.second;
    else if (L.first == R.first)
        return L.second.first > R.second.first;
    else
        return L.first > R.first;
}

void knapsack (int profits[] , int weights[] , int n , int capasity)
{
    vector<pair<float, pair<int, int>>> bestProfite;
    for (int i = 0; i < n; i++)
    {
        float ProfiteByWeight = static_cast<float>(profits[i]) / weights[i];
        bestProfite.push_back({ProfiteByWeight, {profits[i], weights[i]}});
    }
    // sort it Depend on the P/W
    sort(bestProfite.begin(), bestProfite.end(), cmp);

    cout << "\nThe Best Profit_By_Weight , profites, Weight !!!\n";
    for(int i = 0; i < bestProfite.size(); i++)
    {
        cout << "#" << i + 1 << " : " << bestProfite[i].first << "  <=>  "; 
        cout << bestProfite[i].second.first << "  <=>  " << bestProfite[i].second.second << '\n';
    }
    
    // Max profite and Weight
    int MaxProfite = 0, MaxWeight = 0;
    for (int i = 0; i < n; i++)
    {
        // if the bag can't take more
        if (capasity < bestProfite[i].second.second)
            break;
        else
        {
            MaxProfite += bestProfite[i].second.first;
            MaxWeight += bestProfite[i].second.second;
            capasity -= bestProfite[i].second.second;
        }
    }

    cout << "\nMax Possible Weight  : " << MaxWeight << '\n'; 
    cout << "\nMax Possible Profite : " << MaxProfite << '\n'; 
}

int main ()
{
    int n;
    cout << "Enter the number of objects : ";
    cin >> n;
    int profits[n] , weight[n];
    cout << "Enter the profit of each object !\n";
    for (int i = 0; i < n; i++)
        cin >> profits[i];
    cout << "Enter the weight of each object !\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    int capsity;
    cout << "Enter the capacity of the bag (kg) : ";
    cin >> capsity;
    knapsack (profits , weight , n , capsity);
}