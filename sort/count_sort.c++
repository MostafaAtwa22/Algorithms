#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5;

void countingSort(int arr[], int n, int Max)
{
    int count[N] = {0}; // Initialize count array with zeros

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int j = 0;
    for(int i = 0; i <= Max; i++)
    {
        while (count[i]--)
        {
            arr[j++] = i;
        }
    }
}

void SortWithNeg(int arr[], int n, int Min, int Max)
{
    int count[Max - Min + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i] - Min]++;
    int j = 0;
    for (int i = 0; i <= Max - Min; i++)
    {
        while (count[i]--)
        {
            arr[j++] = i + Min;
        }
    }
}

void print(int arr[], int n)
{
    cout << "Array: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int Max = -N;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        Max = max(Max, arr[i]);
    }

    countingSort(arr, size, Max);
    print(arr, size);

    int n;
    cout << "Enter the size : ";
    cin >> n;
    cout << "Enter the element (Negative Value is allowed) !!\n";
    int a[n];
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
    }
    SortWithNeg(a, n, MIN, MAX);
    print(a, n);
}
