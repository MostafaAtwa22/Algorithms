#include <iostream>
using namespace std;

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

    Quick_sort_min(arr , 0 , size - 1);
    print(arr , size);

    Quick_sort_max(arr , 0 , size - 1);
    print(arr , size);

}

int partitioning_min(int arr[], int left, int right)
{

}

void Quick_sort_min(int arr[], int l, int r)
{
	int pivot = partitioning_min(arr, l, r);
	Quick_sort_min(arr, l, pivot - 1)
}


int partitioning_max(int arr[], int left, int right)
{
    int i = left;
    int j = right;
	int pivLoc = i;

	while (true)
	{
		while (arr[pivLoc] > arr[j] && pivLoc != j)
		{
			j--;
		}

		if (pivLoc == j)
			break;

		else if (arr[pivLoc] <= arr[j])
		{
			swap(arr[j], arr[pivLoc]);
			pivLoc = j;
		}

		while (arr[pivLoc] <= arr[i] && pivLoc != i)
		{
			i++;
		}
        
		if (pivLoc == i)
			break;

		else if (arr[pivLoc] > arr[i])
		{
			swap(arr[i], arr[pivLoc]);
			pivLoc = i;
		}
	}
    
	return pivLoc;
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
