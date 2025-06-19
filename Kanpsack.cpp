#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int index, int capacity, const vector<int>& profit, const vector<int>& weight, vector<vector<int>>& dp) {
    if (capacity == 0 || index >= profit.size()) {
        return 0;
    }

    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    int exclude = knapsack(index + 1, capacity, profit, weight, dp);

    int include = 0;
    if (capacity >= weight[index]) {
        include = profit[index] + knapsack(index, capacity - weight[index], profit, weight, dp);
    }

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main() {
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> w;

    vector<int> profit(n), weight(n);
    cout << "Enter the profit of each item: ";
    for (int i = 0; i < n; ++i) {
        cin >> profit[i];
    }

    cout << "Enter the weight of each item: ";
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    int result = knapsack(0, w, profit, weight, dp);
    cout << "The maximum profit is: " << result << endl;

    return 0;
}
