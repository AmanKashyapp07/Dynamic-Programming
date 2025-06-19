#include <iostream>
#include <vector>

// Function to calculate the nth Fibonacci number using DP + Memoization
int fibonacci(int n, std::vector<int>& memo) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Check if the value is already computed
    if (memo[n] != -1) return memo[n];

    // Compute the value and store it in the memo table
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Create a memoization table initialized with -1
    std::vector<int> memo(n + 1, -1);

    // Calculate the nth Fibonacci number
    int result = fibonacci(n, memo);

    std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;

    return 0;
}
