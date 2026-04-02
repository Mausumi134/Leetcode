class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector dp(
            m, vector(n, array<int, 3>{INT_MIN / 2, INT_MIN / 2, INT_MIN / 2}));

        dp[0][0][0] = coins[0][0];
        for (int k = 1; k <= 2; k++) {
            dp[0][0][k] = max(coins[0][0], 0);
        }
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            for (int k = 1; k <= 2; k++) {
                dp[0][j][k] = max(dp[0][j - 1][k] + coins[0][j],
                                  dp[0][j - 1][k - 1] + max(coins[0][j], 0));
            }
        }
        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k] + coins[i][0],
                                  dp[i - 1][0][k - 1] + max(coins[i][0], 0));
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] =
                    max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] =
                        max(max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i][j],
                            max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};