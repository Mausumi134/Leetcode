class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        if (total % 2) return false;

        if (check(rowSum, total)) return true;

        if (check(colSum, total)) return true;

        return false;
    }

    bool check(vector<long long>& arr, long long total) {
        long long left = arr[0];
        long long right = total - left;

        for (int i = 1; i < arr.size(); i++) {
            if (left == right) return true;
            else if(left>right) return false;
            left += arr[i];
            right -= arr[i];
        }
        
        return false;
    }
};