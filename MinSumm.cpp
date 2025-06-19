#include <bits/stdc++.h>
using namespace std;

int dfs(int idx, int sz, int sum, int tot, int n, vector<int> &nums, vector<vector<int>> &dp) {
    if (sz == n) return abs(sum - (tot - sum));
    if (idx == nums.size()) return INT_MAX;
    if (dp[idx][sz] != -1) return dp[idx][sz];
    return dp[idx][sz] = min(dfs(idx + 1, sz + 1, sum + nums[idx], tot, n, nums, dp), 
                             dfs(idx + 1, sz, sum, tot, n, nums, dp));
}

int minimumDifference(vector<int> &nums) {
    int n = nums.size() / 2, tot = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(nums.size(), vector<int>(n + 1, -1));
    return dfs(0, 0, 0, tot, n, nums, dp);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << minimumDifference(nums) << endl;
    return 0;
}
