#include <iostream>
using namespace std;

/**
 * Time  : O(NlogN)
 * Space : O(1)
*/
void heapify_max(int arr[] , int size , int pos);
void heap_build_max(int arr[] , int size);
void Heap_sort_min(int arr[] , int size);

void heapify_min(int arr[] , int size , int pos);
void heap_build_min(int arr[] , int size);
void Heap_sort_max(int arr[] , int size);

void print(int arr[] , int size);

int main()
{
    int size;
    cout << "Enter a size : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)  
        cin >> arr[i];

    Heap_sort_min(arr , size);
    print(arr , size);

    Heap_sort_max(arr , size);
    print(arr , size);
}

void heapify_max(int arr[] , int size , int pos)
{
    // the equ of the left child
    int left = (2 * pos) + 1;
    // the equ of the right child
    int right = (2 * pos) + 2;
    // to comper max elements
    int max = pos;

    if ((arr[left] > arr[max]) && (left < size))
        max = left;
    
    if ((arr[right] > arr[max]) && (right < size))
        max = right;

    if (max != pos)
    {
        swap(arr[max] , arr[pos]);
        heapify_max(arr , size , max);
    }
}

void heap_build_max(int arr[] , int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--)
        heapify_max(arr , size , i);
}

void Heap_sort_min(int arr[] , int size)
{
    heap_build_max(arr , size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0] , arr[i]);
        heapify_max(arr , i , 0);
    }
}

void heapify_min(int arr[] , int size , int pos)
{
    // the equ of the left child
    int left = (2 * pos) + 1;
    // the equ of the right child
    int right = (2 * pos) + 2;
    // to comper max elements
    int max = pos;

    if ((arr[left] < arr[max]) && (left < size))
        max = left;
    
    if ((arr[right] < arr[max]) && (right < size))
        max = right;

    if (max != pos)
    {
        swap(arr[max] , arr[pos]);
        heapify_min(arr , size , max);
    }
}

void heap_build_min(int arr[] , int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--)
        heapify_min(arr , size , i);
}

void Heap_sort_max(int arr[] , int size)
{
    heap_build_min(arr , size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0] , arr[i]);
        heapify_min(arr , i , 0);
    }
}

void print(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}