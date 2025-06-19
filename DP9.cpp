#include <bits/stdc++.h>
using namespace std;

bool isPredecessor(const string& prev, const string& curr) {
    if (curr.size() != prev.size() + 1)
        return false;

    int i = 0, j = 0;
    int diff = 0; // counts how many extra chars we've skipped in curr

    while (i < (int)prev.size() && j < (int)curr.size()) {
        if (prev[i] == curr[j]) {
            i++;
            j++;
        } else {
            diff++;
            if (diff > 1)
                return false;
            j++; // skip one char in curr
        }
    }
    return true;
}

// dp with two states: current index and previous chosen index
int dfs(int current, int prev, const vector<string> &words, vector<vector<int>> &memo) {
    if (current == (int)words.size()) return 0;

    if (memo[current][prev + 1] != -1) return memo[current][prev + 1];

    // Option 1: skip current word
    int ans = dfs(current + 1, prev, words, memo);

    // Option 2: include current word if valid
    if (prev == -1 || isPredecessor(words[prev], words[current])) {
        ans = max(ans, 1 + dfs(current + 1, current, words, memo));
    }

    return memo[current][prev + 1] = ans;
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    int n = (int)words.size();
    // memo dimensions: n x (n+1) because prev can be -1 to n-1, shifted by +1 to avoid negative indexing
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    return dfs(0, -1, words, memo);
}

int main() {
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout << longestStrChain(words) << "\n"; // Output: 4
    return 0;
}
