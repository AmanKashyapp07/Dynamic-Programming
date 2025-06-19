#include <iostream>
#include <vector>
#include <string>

using namespace std;

string lcsHelper(const string &text1, const string &text2, int i, int j, vector<vector<string>> &memo) {
    if (i == (int)text1.length() || j == (int)text2.length()) {
        return "";
    }

    if (!memo[i][j].empty()) {
        return memo[i][j];
    }

    if (text1[i] == text2[j]) {
        memo[i][j] = text1[i] + lcsHelper(text1, text2, i + 1, j + 1, memo);
    } else {
        string lcs1 = lcsHelper(text1, text2, i + 1, j, memo);
        string lcs2 = lcsHelper(text1, text2, i, j + 1, memo);

        if (lcs1.length() > lcs2.length()) {
            memo[i][j] = lcs1;
        } else {
            memo[i][j] = lcs2;
        }
    }

    return memo[i][j];
}

string longestCommonSubsequence(const string &text1, const string &text2) {
    int n = (int)text1.length();
    int m = (int)text2.length();

    vector<vector<string>> memo(n, vector<string>(m, ""));

    return lcsHelper(text1, text2, 0, 0, memo);
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    string lcs = longestCommonSubsequence(text1, text2);

    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << lcs.length() << endl;

    return 0;
}
