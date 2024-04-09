#include <iostream>
using namespace std;

void search(int arr[] , int size , int element);

int main()
{
    int size;
    cout << "Enter the size : ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int element;
    cout << "Enter the element u search for : ";
    cin >> element;
    search(arr , size , element);
    return 0;
}

void search(int arr[] , int size , int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            cout << "Found !\n";
            return;
        }
    }
    cout << "Not found !\n";
}