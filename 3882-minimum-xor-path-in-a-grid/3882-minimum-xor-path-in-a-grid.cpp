class Solution {
public:
    int solve(int i, int j, int n, int m,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        if (i >= n || j >= m) return -1;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j][0] != -1)
            return dp[i][j][0];

        return 0;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(m, vector<bool>(1024, false))
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x])
                            dp[i][j][x ^ grid[i][j]] = true;
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x])
                            dp[i][j][x ^ grid[i][j]] = true;
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][m - 1][x])
                return x;
        }

        return 0;
    }
};