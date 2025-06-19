#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcsHelper(const string &text1, const string &text2, int i, int j, vector<vector<int>> &memo) {
    if (i == text1.length() || j == text2.length()) {
        return 0;
    }


    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (text1[i] == text2[j]) {
        memo[i][j] = 1 + lcsHelper(text1, text2, i + 1, j + 1, memo);
    } else {
        // If characters do not match, explore both possibilities
        memo[i][j] = max(lcsHelper(text1, text2, i + 1, j, memo),
                         lcsHelper(text1, text2, i, j + 1, memo));
    }

    return memo[i][j];
}

int longestCommonSubsequence(const string &text1, const string &text2) {
    int n = text1.length();
    int m = text2.length();

    // Create a memoization table initialized with -1
    vector<vector<int>> memo(n, vector<int>(m, -1));

    return lcsHelper(text1, text2, 0, 0, memo);
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    int result = longestCommonSubsequence(text1, text2);
    cout << "The length of the longest common subsequence is: " << result << endl;

    return 0;
}
