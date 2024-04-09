#include <iostream> 
#include <queue>
#include <vector> 
using namespace std;

int algorithm (int files[] , int n)
{
    // use the min heap to get the smallest size of files every time for merging
    priority_queue <int , vector <int> , greater <int>> min_files;
    // first push all the files's size to the pq
    for (int i = 0; i < n; i++)
        min_files.push (files[i]);
    // to get the min coast of merging
    int coast = 0;
    while (min_files.size () > 1)
    {
        // get the smallest files and merge them
        int first = min_files.top ();
        min_files.pop ();
        int second = min_files.top ();
        min_files.pop ();
        int sum = first + second; 
        coast += sum;
        // and push the new merged file to the pq again 
        min_files.push (sum);
    }
    return coast;
}

int main ()
{
    int n;
    cout << "Enter the # of files : ";
    cin >> n;
    cout << "Enter the files's size !\n";
    int files[n];
    for (auto &i : files)
        cin >> i;
    cout << "The optimal solution : " << algorithm (files , n);
}