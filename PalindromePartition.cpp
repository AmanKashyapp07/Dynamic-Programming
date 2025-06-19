#include <vector>
#include <string>

class Solution {
public:
    void findPartitions(int start, const std::string &s, std::vector<std::string> &currentPartition, 
                        std::vector<std::vector<std::string>> &result, const std::vector<std::vector<bool>> &isPalin) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalin[start][end]) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                findPartitions(end + 1, s, currentPartition, result, isPalin);
                currentPartition.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        int n = s.length();
        std::vector<std::vector<bool>> isPalin(n, std::vector<bool>(n, false));

        
        for (int end = 0; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPalin[start + 1][end - 1])) {
                    isPalin[start][end] = true;
                }
            }
        }

        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPartition;
        findPartitions(0, s, currentPartition, result, isPalin);
        return result;
    }
};
