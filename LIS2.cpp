#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate the LIS with recursion and memoization
int lisHelper(int index, int prevIndex, const vector<int>& nums, vector<vector<int>>& memo, int currentcount, int &finalLIS, int &finalcount) {
    if (index == nums.size()) {
        if (currentcount > finalLIS) {
            finalLIS = currentcount;
            finalcount = 1;
        } else if (currentcount == finalLIS) {
            finalcount++;
        }
        return 0; 
    }

    if (memo[index][prevIndex + 1] != -1) {
        return memo[index][prevIndex + 1];
    }

    int exclude = lisHelper(index + 1, prevIndex, nums, memo, currentcount, finalLIS, finalcount);

    int include = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        include = 1 + lisHelper(index + 1, index, nums, memo, currentcount + 1, finalLIS, finalcount);
    }

    return memo[index][prevIndex + 1] = max(exclude, include);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    int finalLIS = 0, finalcount = 0;

    lisHelper(0, -1, nums, memo, 0, finalLIS, finalcount);

    return finalcount;
}

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "Number of Longest Increasing Subsequences: " << lengthOfLIS(nums) << endl;
    return 0;
}
