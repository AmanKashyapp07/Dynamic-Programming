#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate the LIS with recursion and memoization
int lisHelper(int index, int prevIndex, const vector<int>& nums, vector<vector<int>>& memo, vector<int>& currentLIS, vector<int>& finalLIS) {
    if (index == nums.size()) {
        if (currentLIS.size() > finalLIS.size()) {
            finalLIS = currentLIS;
        }
        return 0; 
    }


    if (memo[index][prevIndex + 1] != -1) {
        return memo[index][prevIndex + 1];
    }

    
    int exclude = lisHelper(index + 1, prevIndex, nums, memo, currentLIS, finalLIS);

    // Option 2: Include the current element if it forms an increasing subsequence
    int include = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        currentLIS.push_back(nums[index]); // Add current element to currentLIS
        include = 1 + lisHelper(index + 1, index, nums, memo, currentLIS, finalLIS);
        currentLIS.pop_back(); // Backtrack
    }


    return memo[index][prevIndex + 1] = max(exclude, include);
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    vector<int> currentLIS, finalLIS;


    int length = lisHelper(0, -1, nums, memo, currentLIS, finalLIS);


    cout << "Longest Increasing Subsequence: ";
    for (int num : finalLIS) {
        cout << num << " ";
    }
    cout << endl;

    return length;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}
