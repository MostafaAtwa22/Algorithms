#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void search_recursive(vector<int> & arr , int element , int left , int right);
void search(vector<int> & arr , int element , int left , int right);

int main()
{
    int size , num;
    cout << "Enter the size : ";
    cin >> size;
    vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin() , arr.end());

    int element;
    cout << "Enter the element u search for : ";
    cin >> element;
    search_recursive(arr , element , 0 , size - 1);
    search(arr , element , 0 , size - 1);
    return 0;
}

void search(vector<int> & arr , int element , int left , int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (element == arr[mid])
        {
            cout << "Found !\n";
            return;
        }

        else if (element > arr[mid])
            left = mid + 1;

        else
            right = mid - 1;
    }
    cout << "Not found !\n";
}

void search_recursive(vector<int> & arr , int element , int left , int right)
{
    

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (element == arr[mid])
        {
            cout << "Found !\n";
            return;
        }

        else if (element > arr[mid])
            return search_recursive(arr , element , mid + 1 , right);

        else
            return search_recursive(arr , element , left , mid - 1);
    }
    cout << "Not found !\n";
}