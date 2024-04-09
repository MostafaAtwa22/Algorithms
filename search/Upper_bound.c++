#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// this get the biggest value that <= some element
int Upper_bound(vector<int> & arr, int target)
{
  int l = 0, r = arr.size() - 1, m;
  while (l <= r)
  {
    m = (l + r) / 2;
    if (arr[m] <= target)
      l = m + 1;
    else
      r = m - 1;
  }
  return r;
}

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

  int target;
  cout << "Enter the target u search for : ";
  cin >> target;
  int index = Upper_bound(arr, target);
  if (index == -1)
  {
    cout << "There is no Element Found that Less than or equal {" << target << "}\n"; 
    return 0;
  }
  cout << "The index  : " << index << '\n';
  cout << "The Target : " << arr[index] << '\n';
}
