#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Time  : O(NlogN)
 * Space : O(N)
*/
template<typename T>
void merge(vector<T> & leftArray, vector<T> & rightArray, vector<T> & a)
{
    int leftSize = a.size() / 2;
    int rightSize = a.size() - leftSize;
    int l = 0, r = 0, i = 0; // indices of the merging 

    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
            a[i++] = leftArray[l++];
        else
            a[i++] = rightArray[r++];
    }
    // if there are remaining elements in the left array
    while (l < leftSize)
    {
        a[i++] = leftArray[l++];
    }
    // if there are remaining elements in the right array
    while (r < rightSize)
    {
        a[i++] = rightArray[r++];
    }
}

template<typename T>
void sort(vector<T> & a)
{
    int size = a.size();
    if (size <= 1)
        return;
    int mid = size / 2;
    vector<T> leftArray(mid);
    vector<T> rightArray(size - mid);

    // copy the left elements of 'a' to 'leftArray' and the right to 'rightArray'
    int i = 0, j = 0;
    for (; i < size; i++)
    {
        if (i < mid)
            leftArray[i] = a[i];
        else 
            rightArray[j++] = a[i];
    }
    sort(leftArray);
    sort(rightArray);
    merge(leftArray, rightArray, a);
}

template<typename T>
void print (vector<T> & a)
{
    cout << "Array : [ ";
    for(auto &i : a)
        cout << i << ' ';
    cout << "]\n";
}

int main()
{
    cout << "Enter the size of the Array : ";
    int size; 
    cin >> size;
    vector<int> a(size);
    cout << "Enter the Array Elements !!!\n";
    for (auto &i : a)
        cin >> i;
    sort(a);
    print(a);
}
