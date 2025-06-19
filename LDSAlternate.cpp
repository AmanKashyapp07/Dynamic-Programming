#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nums;  // Global copy of nums for easy access
    vector<vector<vector<int>>> memo;

    vector<int> findLargestSubset(int currentIndex, int lastIndex) {
        // Base case: If we reach the end of the array, return an empty subset
        if (currentIndex >= nums.size()) {
            return {};
        }

        // Check memo
        if (memo[currentIndex][lastIndex + 1] != vector<int>{-1}) {
            return memo[currentIndex][lastIndex + 1];
        }

        // Option 1: Exclude the current element
        vector<int> exclude = findLargestSubset(currentIndex + 1, lastIndex);

        // Option 2: Include the current element if it is divisible
        vector<int> include;
        if (lastIndex == -1 || nums[currentIndex] % nums[lastIndex] == 0) {
            include.push_back(nums[currentIndex]); // Push the current element first
            vector<int> nextSubset = findLargestSubset(currentIndex + 1, currentIndex);
            include.insert(include.end(), nextSubset.begin(), nextSubset.end());
        }

        // Choose the larger subset
        vector<int> result = (include.size() > exclude.size()) ? include : exclude;

        // Store in memo
        return memo[currentIndex][lastIndex + 1] = result;
    }

    vector<int> largestDivisibleSubset(vector<int>& arr) {
        if (arr.empty()) return {};
        
        sort(arr.begin(), arr.end());
        nums = arr;
        int n = nums.size();
        memo.assign(n, vector<vector<int>>(n + 1, vector<int>{-1}));

        return findLargestSubset(0, -1);
    }
};
