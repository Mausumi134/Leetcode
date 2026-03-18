class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<vector<int>>>& dp,int n,int cap){
        if(i==n || cap==0)return 0;

        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit=0;
        if(buy==0){
           profit=max(solve(i+1,0,prices,dp,n,cap),-prices[i]+solve(i+1,1,prices,dp,n,cap));
        }
        else{
            profit=max(solve(i+1,1,prices,dp,n,cap),prices[i]+solve(i+1,0,prices,dp,n,cap-1));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,prices,dp,n,2);
    }
};