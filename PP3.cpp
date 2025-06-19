#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find if we can divide into exactly `k` palindromic partitions.
bool canPartition(int i, int n, int k, string &str, vector<vector<int>> &dp) {
    // Base cases.
    if (k == 0) return i == n;  // If no partitions left, check if we reached the end.
    if (i == n) return false;   // If reached end and still need partitions, return false.

    if (dp[i][k] != -1) return dp[i][k];

    // Check for all possible substrings starting from index `i`.
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // Recur for the next partition with `k - 1` remaining.
            if (canPartition(j + 1, n, k - 1, str, dp)) {
                return dp[i][k] = true;
            }
        }
    }
    return dp[i][k] = false;
}

// Main function to check if the string can be divided into `k` palindromic partitions.
bool canDivideIntoKPalindromes(string str, int k) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return canPartition(0, n, k, str, dp);
}

int main() {
    string str = "BABABCBADCEDE";
    int k = 3; // Change this to test for different values of k.
    if (canDivideIntoKPalindromes(str, k)) {
        cout << "The string can be divided into " << k << " palindromic partitions.\n";
    } else {
        cout << "The string cannot be divided into " << k << " palindromic partitions.\n";
    }
    return 0;
}
