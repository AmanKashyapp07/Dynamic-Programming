#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum coins obtained
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp, int leftBoundary, int rightBoundary) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int maxCoins = INT_MIN;
    

    for (int k = i; k <= j; k++) {

        int coins = leftBoundary * nums[k] * rightBoundary;
        
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp, leftBoundary, nums[k]) +
                             maxCoinsHelper(k + 1, j, nums, dp, nums[k], rightBoundary);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return dp[i][j] = maxCoins;
}


int maxCoins(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return maxCoinsHelper(0, n - 1, nums, dp, 1, 1);
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    int maxCoinsResult = maxCoins(nums);
    cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
    return 0;
}
