class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<long long>>prefix(m,vector<long long>(n,0));

        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long top=(i>0)?prefix[i-1][j]:0;
                long long left=(j>0)?prefix[i][j-1]:0;
                long long diag=(i>0 && j>0)?prefix[i-1][j-1]:0;

                prefix[i][j]=grid[i][j]+top+left-diag;

                if(prefix[i][j]<=k)count++;
            }
        }
        return count;
    }
};