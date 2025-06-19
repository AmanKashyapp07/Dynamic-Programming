#include <iostream>
#include <vector>
using namespace std;


int dp(int index, int prevIndex, const vector<int>& nums, vector<vector<int>>& memo) {
    if (index == nums.size()) {
        return 0; 
    }

    if (memo[index][prevIndex + 1] != -1) {
        return memo[index][prevIndex + 1];
    }

    // Option 1: Skip the current element
    int exclude = dp(index + 1, prevIndex, nums, memo);

    // Option 2: Include the current element if it forms an increasing subsequence
    int include = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        include = 1 + dp(index + 1, index, nums, memo);
    }

    memo[index][prevIndex + 1] = max(exclude, include);
    return memo[index][prevIndex + 1];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    return dp(0, -1, nums, memo);
}

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}
