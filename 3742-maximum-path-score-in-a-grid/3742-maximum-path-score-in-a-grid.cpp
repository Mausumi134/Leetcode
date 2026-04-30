class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        dp[0][0][0]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int c=0;c<=k;c++){
                    if(dp[i][j][c]==-1)continue;

                  


                    if(j+1<m){
                        int nextval=grid[i][j+1];
                        int s=(nextval==0?0:nextval);
                        int cost=(nextval==0?0:1);

                        int newcost=c+cost;
                        if(newcost<=k){
                            dp[i][j+1][newcost]=max(dp[i][j+1][newcost],dp[i][j][c]+s);
                        }
                    }
                    if(i + 1 < n) {
                        int nextVal = grid[i+1][j];
                        int s = (nextVal == 0 ? 0 : nextVal);
                        int cost = (nextVal == 0 ? 0 : 1);

                        int newCost = c + cost;
                        if(newCost <= k) {
                            dp[i+1][j][newCost] = max(dp[i+1][j][newCost],dp[i][j][c] + s);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int c = 0; c <= k; c++) {
            ans = max(ans, dp[n-1][m-1][c]);
        }

        return ans;
    }
};