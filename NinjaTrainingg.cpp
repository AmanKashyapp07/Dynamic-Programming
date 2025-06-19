#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxPoints(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        int n = points.size();
        if (day == n) return 0;

        if (dp[day][last] != -1) return dp[day][last];

        int maxPoints = 0;

        for (int activity = 0; activity < 3; activity++) {
            if (activity != last) {
                int currentPoints = points[day][activity] + getMaxPoints(day + 1, activity, points, dp);
                maxPoints = max(maxPoints, currentPoints);
            }
        }

        return dp[day][last] = maxPoints;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int maxPoints = 0;

        for (int activity = 0; activity < 3; activity++) {
            maxPoints = max(maxPoints, points[0][activity] + getMaxPoints(1, activity, points, dp));
        }

        return maxPoints;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));
    cout << "Enter the merit points for Running, Fighting Practice, and Learning New Moves for each day:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    int result = sol.ninjaTraining(n, points);
    cout << "Maximum merit points the ninja can earn: " << result << endl;

    return 0;
}
