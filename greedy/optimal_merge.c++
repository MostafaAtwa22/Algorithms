#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/* in this problem we have size of linked list and we want to merge them with min coast */
/* problem link (explaining) : https://youtu.be/HHIc5JZyenI */

int merge (int lists[], int n)
{
    // use it to sort it according to it's size
    priority_queue <int, vector <int>, greater <int>> sorting;
    // push the elements to the que
    for (int i = 0; i < n; i++)
        sorting.push (lists[i]);
    int coast = 0;
    while (sorting.size () > 1)
    {
        int first = sorting.top ();
        sorting.pop ();
        int second = sorting.top ();
        sorting.pop ();
        int sum = first + second;
        sorting.push (sum);
        coast += sum;
    }
    return coast;
}

int main (void)
{
    int n;
    cout << "The number of linked lists : ";
    cin >> n;
    int lists [n];
    for (int i = 0; i < n; i++)
        cin >> lists[i];
    cout << "The min coast = " << merge (lists, n) << '\n';
}