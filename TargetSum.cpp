#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findWays(int index, int currentSum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (index == nums.size()) {
            return currentSum == target ? 1 : 0;
        }

        
        int dpIndex = currentSum + offset; 
        if (dp[index][dpIndex] != -1) {
            return dp[index][dpIndex];
        }
        int add = findWays(index + 1, currentSum + nums[index], nums, target, dp, offset);
        int subtract = findWays(index + 1, currentSum - nums[index], nums, target, dp, offset);
        return dp[index][dpIndex] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;
        if (abs(target) > sum) return 0;

        // Offset to handle negative sums
        int offset = sum;

        // DP array: index x [-sum to sum] shifted by offset
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        // Start the recursion
        return findWays(0, 0, nums, target, dp, offset);
    }
};



