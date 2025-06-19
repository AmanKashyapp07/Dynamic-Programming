#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
        return countSubsequences(s, t, 0, 0, memo);
    }

private:
    int countSubsequences(const string &s, const string &t, int i, int j, vector<vector<int>> &memo) {
        if (j == t.size()) return 1; // Found a valid subsequence
        if (i == s.size()) return 0; // Reached end of s without matching t

        if (memo[i][j] != -1) return memo[i][j];

        // Option 1: Skip the current character of s
        int skipCurrent = countSubsequences(s, t, i + 1, j, memo);

        // Option 2: Use the current character of s (if it matches t[j])
        int useCurrent = 0;
        if (s[i] == t[j]) {
            useCurrent = countSubsequences(s, t, i + 1, j + 1, memo);
        }

        memo[i][j] = skipCurrent + useCurrent;
        return memo[i][j];
    }
};
