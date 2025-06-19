#include <iostream>
#include <vector>
#include <cmath>
#include <climits>


int minEnergy(int n, int k, const std::vector<int>& heights, std::vector<int>& dp) {
    if (n == 0) return 0; 
    if (dp[n]!=-1) return dp[n];

    // Initialize the minimum energy to a large value
    int minEnergyRequired = INT_MAX;


    for (int j = 1; j <= k; ++j) {
        if (n - j >= 0) {
            int jumpEnergy = minEnergy(n - j, k, heights, dp) + std::abs(heights[n] - heights[n - j]);
            minEnergyRequired = std::min(minEnergyRequired, jumpEnergy);
        }
    }

    dp[n] = minEnergyRequired;
    return dp[n];
}

int main() {
    int n, k;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    std::cout << "Enter the maximum jump distance (k): ";
    std::cin >> k;

    std::vector<int> heights(n);
    std::cout << "Enter the heights of the steps: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }


    std::vector<int> dp(n, -1);
    int result = minEnergy(n - 1, k, heights, dp);

    std::cout << "The minimum energy required is: " << result << std::endl;

    return 0;
}
