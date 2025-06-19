#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp(int amount, vector<int> &coins, int p, int total,
           vector<vector<int>> &memo)
    {
        if (total > amount)
            return INT_MAX-1;
        if (total == amount)
            return 0;
        if (p >= coins.size())
            return INT_MAX-1;
        if (memo[p][total] != -1)
            return memo[p][total];

        int in = 1+dp(amount, coins, p, total + coins[p], memo);
        int ex = dp(amount, coins, p + 1, total, memo);

        memo[p][total] = min(in, ex);
        return memo[p][total];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int result = dp(amount, coins, 0, 0, memo);
        return result == INT_MAX-1  ? -1 : result;
    }
};