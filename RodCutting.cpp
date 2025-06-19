#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRevenue(int rodLength, const vector<int>& price, vector<int>& dp) {
    if (rodLength <= 0) {
        return 0;
    }

    if (dp[rodLength] != -1) {
        return dp[rodLength];
    }

    int maxCost = 0;

    for (int i = 1; i <= rodLength; ++i) {
        maxCost = max(maxCost, price[i - 1] + maxRevenue(rodLength - i, price, dp));
    }

    dp[rodLength] = maxCost;
    return maxCost;
}

int main() {
    int N; 
    cout << "Enter the length of the rod: ";
    cin >> N;

    vector<int> price(N);
    cout << "Enter the prices of pieces of length 1 to " << N << ": ";
    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }

   
    vector<int> dp(N + 1, -1);

    int result = maxRevenue(N, price, dp);
    cout << "The maximum revenue is: " << result << endl;

    return 0;
}
