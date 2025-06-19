#include <bits/stdc++.h>
using namespace std;


int matrixMultiplication(vector<int>& arr, int N) {
    int dp[N][N];

    for (int i = 1; i < N; i++) {
        dp[i][i] = 0;
    }


    for (int i=N-1;i>0;i--) {
        for (int j=i+1;j<N;j++) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    
    return dp[1][N - 1];
}

int main() {
    vector<int> arr = {4,5,3,2};
    int n = arr.size();

    cout << "The minimum number of operations for matrix multiplication is " << matrixMultiplication(arr, n) << endl;

    return 0;
}