class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>>& dp,int n){
        if(i==n)return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy==0){
           profit=max(solve(i+1,0,prices,dp,n),-prices[i]+solve(i+1,1,prices,dp,n));
        }
        else{
            profit=max(solve(i+1,1,prices,dp,n),prices[i]+solve(i+1,0,prices,dp,n));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp,n);
    }
};