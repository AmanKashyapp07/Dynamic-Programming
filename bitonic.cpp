#include <bits/stdc++.h>
using namespace std;


int dfs(int index, int prev, int flag, const vector<int>& nums, vector<vector<vector<int>>>& dp) {
    if (index == nums.size()) return 0;

    if (dp[index][prev + 1][flag] != -1) return dp[index][prev + 1][flag];

    // Option 1: Skip the current element
    int maxLength = dfs(index + 1, prev, flag, nums, dp);

    // Option 2: Include the current element
    if (flag == 0 && (prev == -1 || nums[index] > nums[prev])) {
        // Still in increasing phase
        maxLength = max(maxLength, 1 + dfs(index + 1, index, 0, nums, dp));
    } else if (flag == 0) {
        // Switch to decreasing phase
        maxLength = max(maxLength, 1 + dfs(index + 1, index, 1, nums, dp));
    } else if (flag == 1 && (prev == -1 || nums[index] < nums[prev])) {
        // Still in decreasing phase
        maxLength = max(maxLength, 1 + dfs(index + 1, index, 1, nums, dp));
    }

    return dp[index][prev + 1][flag] = maxLength;
}

int longestBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    return dfs(0, -1, 0, nums, dp);
}

int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << longestBitonicSubsequence(nums) << endl; 
    return 0;
}
