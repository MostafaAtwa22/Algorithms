#include <iostream>
using namespace std;

int count[100];
int sorted[100];

void sort(int arr[] , int n)
{
    for (int i = n - 1; i >= 0; i--)
        sorted[--count[arr[i]]] = arr[i];
}

void print (int n)
{
    for (int i = 0; i < n; i++)
        cout << sorted[i] << ' ';
}
int main()
{
    int size;
    cout << "Enter a size : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)  
    {
        cin >> arr[i];
        count[arr[i]]++;
    }
    for (int i = 1; i < 100; i++)
        count[i] += count[i - 1];
    
    sort(arr , size);
    print(size);
} 
