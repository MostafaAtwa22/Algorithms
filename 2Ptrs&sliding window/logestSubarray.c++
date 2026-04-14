#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSubarray(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int sum = 0;
    while (right < nums.size()) { 
        sum += nums[right];
        while (sum > k) { // optimal if (sum > k)
            sum -= nums[left];
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 10;
    cout << longestSubarray(nums, k) << endl;
    return 0;
}