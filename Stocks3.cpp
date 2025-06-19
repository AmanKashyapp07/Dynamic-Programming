#include <bits/stdc++.h>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy1 = INT_MAX, profit1 = 0;
        int buy2 = INT_MAX, profit2 = 0;

        for (int price : prices) {
            // Update first buy and first profit
            buy1 = std::min(buy1, price);
            profit1 = std::max(profit1, price - buy1);

            // Update second buy and second profit
            buy2 = std::min(buy2, price - profit1); // Effective price for second buy
            profit2 = std::max(profit2, price - buy2);
        }

        return profit2;
    }
};
