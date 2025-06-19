#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return {};

        sort(arr.begin(), arr.end());

        vector<int> length(n, 1);
        vector<int> prev(n, -1);

        int max_len = 1;
        int max_index = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    prev[i] = j;
                }
            }
            if (length[i] > max_len) {
                max_len = length[i];
                max_index = i;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> result;
        int curr = max_index;
        while (curr >= 0) {
            result.push_back(arr[curr]);
            curr = prev[curr];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
