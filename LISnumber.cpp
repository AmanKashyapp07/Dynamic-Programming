#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);     // Length of LIS ending at i
        vector<int> count(n, 1);  // Number of LIS ending at i

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(dp.begin(), dp.end());
        int totalCount = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLength) {
                totalCount += count[i];
            }
        }

        return totalCount;
    }
};

int main() {
    Solution sol;


    vector<int> nums = {1, 3, 5, 4, 7};

    int result = sol.findNumberOfLIS(nums);

    cout << "Number of Longest Increasing Subsequences: " << result << endl;

    return 0;
}
