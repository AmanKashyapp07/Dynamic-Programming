#include <iostream>
#include <vector>
#include <algorithm>

int robHelper(int i, const std::vector<int>& nums, std::vector<int>& dp) {

    if (i == 0) return nums[0];
    if (i == 1) return std::max(nums[0], nums[1]);

    if (dp[i] != -1) return dp[i];

    // Recursive relation: max of skipping or robbing the current house
    dp[i] = std::max(robHelper(i - 1, nums, dp), nums[i] + robHelper(i - 2, nums, dp));
    return dp[i];
}

int rob(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; 
    if (n == 1) return nums[0]; 


    std::vector<int> dp(n, -1);


    return robHelper(n - 1, nums, dp);
}

int main() {
    std::vector<int> nums;
    int n;

    std::cout << "Enter the number of houses: ";
    std::cin >> n;

    std::cout << "Enter the amount of money in each house: ";
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "Maximum amount of money you can rob: " << rob(nums) << std::endl;

    return 0;
}
