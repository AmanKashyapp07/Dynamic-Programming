
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       findMinimumCost(i, ind - 1, cuts, dp) +
                       findMinimumCost(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
        return findMinimumCost(1, c, cuts, dp);
    }
};
