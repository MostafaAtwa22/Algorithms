#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Time  : O(NlogN)
 * Space : O(1)
*/
int partitioning_min(int arr[] , int left , int right);
void Quick_sort_min(int arr[] , int left , int right);
int partitioning_max(int arr[] , int left , int right);
void Quick_sort_max(int arr[] , int left , int right);
void print(int arr[] , int size);

int main()
{
    int size;
    cout << "Enter a size : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)  
        cin >> arr[i];

    Quick_sort_min(arr , 0 , size);
    print(arr , size);

    Quick_sort_max(arr , 0 , size - 1);
    print(arr , size);

}

int partitioning_min(int arr[], int l, int r)
{
	int pivot = arr[l];
	int i = l, j = r;
	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] <= pivot);
		do
		{
			j--;
		} while (arr[j] > pivot);
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void Quick_sort_min(int arr[], int l, int r)
{
	if (l < r)
	{
		int pivot = partitioning_min(arr, l, r);
		Quick_sort_min(arr, l, pivot);
		Quick_sort_min(arr, pivot + 1, r);
	}
}


int partitioning_max(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (pivot < arr[j])
		{
			i++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	i++;
	int tmp = arr[i];
	arr[i] = arr[right];
	arr[right] = tmp;
	return i;
}

void Quick_sort_max(int arr[] , int left , int right)
{
    if (left < right)
    {
        int pivot = partitioning_max(arr , left , right);
        Quick_sort_max(arr , left , pivot - 1);
        Quick_sort_max(arr , pivot + 1 , right);
    }
}

void print(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
