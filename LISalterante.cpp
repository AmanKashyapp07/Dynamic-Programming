#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Initialize DP array with 1
    
    // Compute the LIS for each index
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The LIS length is the maximum value in the DP array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Length of Longest Increasing Subsequence: " << findLIS(arr) << endl;
    return 0;
}
