#include <bits/stdc++.h>
using namespace std;

void precomputePalindrome(string& s, vector<vector<bool>>& isPal) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true; 
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPal[i][i + 1] = true; 
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPal[i + 1][j - 1]) {
                    isPal[i][j] = true;
                }
            }
        }
    }