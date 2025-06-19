#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLargestDivisibleSubset(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    sort(arr.begin(), arr.end()); // Sort the array for increasing order
    vector<vector<int>> dp(n);

    // Initialize each DP element with a single element subset
    for (int i = 0; i < n; ++i) {
        dp[i] = {arr[i]};
    }

    // Compute the largest divisible subset for each index
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0) {
                if (dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(arr[i]);
                }
            }
        }
    }

    // Find the largest subset
    vector<int> largestSubset;
    for (const auto& subset : dp) {
        if (subset.size() > largestSubset.size()) {
            largestSubset = subset;
        }
    }

    return largestSubset;
}

int main() {
    vector<int> arr = {1, 2, 4,8};
    vector<int> result = findLargestDivisibleSubset(arr);

    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
