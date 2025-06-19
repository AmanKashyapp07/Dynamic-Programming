#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> lis; // To store the smallest ending elements of subsequences

    for (int num : nums) {
        // Find the position where 'num' can replace or extend
        auto it = lower_bound(lis.begin(), lis.end(), num);

        if (it == lis.end()) {
            // If num is greater than all elements, append it
            lis.push_back(num);
        } else {
            // Replace the first element >= num
            *it = num;
        }
    }

    // Length of lis is the length of the LIS
    return lis.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " 
         << longestIncreasingSubsequence(nums) << endl; 
    return 0;
}
