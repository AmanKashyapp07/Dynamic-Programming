#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to compute length of longest common substring
int lcsSubstrHelper(const string &text1, const string &text2, int i, int j, int count, vector<vector<vector<int>>> &memo) {
    if (i == (int)text1.length() || j == (int)text2.length()) {
        return count;
    }

    if (memo[i][j][count] != -1) {
        return memo[i][j][count];
    }

    int countWithMatch = count;
    if (text1[i] == text2[j]) {
        countWithMatch = lcsSubstrHelper(text1, text2, i + 1, j + 1, count + 1, memo);
    }

    int countSkipText1 = lcsSubstrHelper(text1, text2, i + 1, j, 0, memo);
    int countSkipText2 = lcsSubstrHelper(text1, text2, i, j + 1, 0, memo);

    memo[i][j][count] = max({countWithMatch, countSkipText1, countSkipText2});
    return memo[i][j][count];
}

int longestCommonSubstring(const string &text1, const string &text2) {
    int n = (int)text1.length();
    int m = (int)text2.length();

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(min(n, m) + 1, -1)));

    return lcsSubstrHelper(text1, text2, 0, 0, 0, memo);
}

int main() {
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    int length = longestCommonSubstring(text1, text2);
    cout << "Length of longest common substring is: " << length << endl;

    return 0;
}
