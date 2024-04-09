#include <iostream> 
#include <algorithm>
#include <utility>
using namespace std;


void knapsack (float profits[] , float weight[] , int n , float capasity)
{
    // the array that calc the (profits / weight)
    pair <float , pair <float , float>> x[n];
    for (int i = 0; i < n; i++)
    {
        x[i].first = (profits[i] / weight[i]);
        x[i].second.first = profits[i];
        x[i].second.second = weight[i];
    }
    // after that sort the x array to get the biggest
    sort (x , x + n);
    cout << "The (profits / weight) desinding !\n";
    for (int i = n - 1; i >= 0; i--)
        cout << x[i].first << ' ';
    cout << endl;

    float sum = capasity , ans = 0.0;
    // this is the way to get the prefits that can be taken
    float bestprof[n] = {};
    int i = 0;
    for (i = n; i >= 0; i--)
    {
        if (sum >= x[i].second.second)
        {
            bestprof[i] = 1.0;
            sum -= x[i].second.second;
        }
        else
            break;
    }
    // to get the remeder the capacity that can be tacken
    bestprof[i] = (sum / x[i].second.second);

    cout << "The best profits !\n";
    for (int j = n - 1; j >= 0; j--)
        cout << bestprof[j] << ' ';

    for (int j = n - 1; j >= 0; j--)
        ans += (bestprof[j] * x[j].second.first);
    
    cout << endl;
    cout << "The optimal soltion = " << ans << '\n';
}   

int main ()
{
    int n;
    cout << "Enter the number of objects : ";
    cin >> n;
    float profits[n] , weight[n];
    cout << "Enter the profit of each object !\n";
    for (int i = 0; i < n; i++)
        cin >> profits[i];
    cout << "Enter the weight of each object !\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    float capsity;
    cout << "Enter the capacity of the bag (kg) : ";
    cin >> capsity;
    knapsack (profits , weight , n , capsity);
}