#include <iostream> 
#include <queue>
#include <vector> 
using namespace std;

int algorithm (int files[] , int n)
{
    // we will use PQ with min heap 
    priority_queue<int, vector<int>, greater<>> MinFileSize;
    for(int i = 0; i < n; i++)
        MinFileSize.push(files[i]);
    // get the min coast of combine 2 files
    int optimalSol = 0;
    // merge utill the size become 1
    while (MinFileSize.size() > 1)
    {
        // get the first 2 min
        int Min1 = MinFileSize.top();
        MinFileSize.pop();
        int Min2 = MinFileSize.top();
        MinFileSize.pop();
        // add merge operation sum to optimal solution
        int sum = Min1 + Min2;
        optimalSol += sum;
        // add the new merged files
        MinFileSize.push(sum);
    }
    return optimalSol;
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