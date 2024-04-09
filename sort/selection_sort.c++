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
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        T min_element = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (min_element > arr[j])
            {
                min_element = arr[j];
                min_index = j;
            }
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }
}

template <typename T>
void max_sort(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int max_index = i;
        T max_element = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (max_element < arr[j])
            {
                max_element = arr[j];
                max_index = j;
            }
        }
        if (max_index != i)
            swap(arr[i], arr[max_index]);
    }
}

template <typename T>
void print(const T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
