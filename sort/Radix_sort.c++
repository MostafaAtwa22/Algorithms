#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

/**
 * Time  : O(N*K)
 * Space : O(N + K)
 * N => size of array
 * K => max number of Digits
 * deals with int only
*/

vector <int> ArrayDigits[10]; // 0 => 9

int NumberOfDigits (int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

void InsertOnArrayDigits(int a[], int size, int digit)
{
    for (int i = 0; i < size; i++)
    {
        int LastDigit = 0;
        int Number = a[i];
        for (int j = 0; j < digit; j++)
        {
            LastDigit = a[i] % 10;
            a[i] /= 10;
        }
        ArrayDigits[LastDigit].push_back(Number);
    }
}

void InsertAfterArrayDigits(int a[])
{
    int i = 0;
    for (int j = 0; j <= 10; j++)
    {
        for (auto k : ArrayDigits[j])
            a[i++] = k;
        ArrayDigits[j].clear();
    }
}

void RadixSort(int a[], int size, int MaxDigit)
{
    for (int i = 1; i <= MaxDigit; i++)
    {
        InsertOnArrayDigits(a, size, i);
        InsertAfterArrayDigits(a);
    }
}

void print(string message, int a[], int size)
{
    cout << message << " : [ ";
    for(int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << "]\n";
}

int main()
{
    int size;
    int MaxDigit = 0;
    cout << "Enter the Size of the Array : ";
    cin >> size;
    int a[size];
    cout << "Enter the Arrary Integer Numbers !!\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
        MaxDigit = max(MaxDigit, NumberOfDigits(a[i]));
    }
    RadixSort(a, size, MaxDigit);
    print("Sorted Array", a, size);
} 