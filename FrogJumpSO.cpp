#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int minEnergy(int n, const std::vector<int>& heights) {
    if (n == 1) return 0; 

    // Initialize variables for the last two states
    int prev1 = 0; // Energy to reach step 0
    int prev2 = std::abs(heights[1] - heights[0]); // Energy to reach step 1

    for (int i = 2; i < n; ++i) {
        // Calculate the minimum energy to reach the current step
        int current = std::min(prev2 + std::abs(heights[i] - heights[i - 1]),
                               prev1 + std::abs(heights[i] - heights[i - 2]));

        // Update the variables for the next iteration
        prev1 = prev2;
        prev2 = current;
    }

    // The last state holds the minimum energy to reach step (n-1)
    return prev2;
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

    // Calculate the minimum energy to reach the last step
    int result = minEnergy(n, heights);

    std::cout << "The minimum energy required is: " << result << std::endl;

    return 0;
}
