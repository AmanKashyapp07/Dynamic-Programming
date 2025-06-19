#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to calculate the minimum energy using DP + Memoization
int minEnergy(int n, const std::vector<int>& heights, std::vector<int>& dp) {
    // Base cases
    if (n == 0) return 0;  // 0th step
    if (n == 1) return std::abs(heights[1] - heights[0]);

    // If already computed, return the stored result
    if (dp[n] != -1) return dp[n];

    // Recursive calculation
    int oneStep = minEnergy(n - 1, heights, dp) + std::abs(heights[n] - heights[n - 1]);
    int twoSteps = 10000;
    if (n > 1) {
        twoSteps = minEnergy(n - 2, heights, dp) + std::abs(heights[n] - heights[n - 2]);
    }

    // Store the result in the memoization table
    dp[n] = std::min(oneStep, twoSteps);
    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    std::vector<int> heights(n);
    std::cout << "Enter the heights of the steps: ";
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    // Create a DP table initialized with -1
    std::vector<int> dp(n, -1);

    // Calculate the minimum energy to reach the last step
    int result = minEnergy(n - 1, heights, dp);

    std::cout << "The minimum energy required is: " << result << std::endl;

    return 0;
}
