#include <iostream>
using namespace std;

/*
* Time  : O(n^2)
* Space : O(1)
*/
template <typename T>
void min_sort(T arr[], int size);

template <typename T>
void max_sort(T arr[], int size);

template <typename T>
void print(const T arr[], int size);

int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;

    int intArr[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
        cin >> intArr[i];

    min_sort(intArr, size);
    cout << "Sorted in ascending order: ";
    print(intArr, size);

    max_sort(intArr, size);
    cout << "Sorted in descending order: ";
    print(intArr, size);

    double doubleArr[size];
    cout << "Enter " << size << " doubles: ";
    for (int i = 0; i < size; i++)
        cin >> doubleArr[i];

    min_sort(doubleArr, size);
    cout << "Sorted in ascending order: ";
    print(doubleArr, size);

    max_sort(doubleArr, size);
    cout << "Sorted in descending order: ";
    print(doubleArr, size);
}

template <typename T>
void min_sort(T arr[], int size)
{
    int j;
    T key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1]  = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}

template <typename T>
void max_sort(T arr[], int size)
{
    int j;
    T key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key > arr[j])
        {
            arr[j + 1]  = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}

template <typename T>
void print(const T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}