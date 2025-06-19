#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void PalindromeCompute(string& s, vector<vector<bool>>& isPalindrome) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true; 
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true; 
            }
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }
    }

    int helper(string& s, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& isPalindrome) {
        if (i >= j) 
            return 0;

        if (isPalindrome[i][j])
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {
            int ans = helper(s, i, k, dp, isPalindrome) + helper(s, k + 1, j, dp, isPalindrome) + 1;
            mini = min(mini, ans);
        }

        return dp[i][j] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        PalindromeCompute(s, isPalindrome);

        return helper(s, 0, n - 1, dp, isPalindrome);
    }
};
