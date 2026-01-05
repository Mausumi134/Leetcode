class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>&dp){
        if(i==0){
            return amount % coins[i]==0?amount/coins[i]:1e9;
        }

        if(dp[i][amount]!=-1)return dp[i][amount];

        int nottake=solve(i-1,coins,amount,dp);
        int take=1e9;

        if(coins[i]<=amount){
            take=1+solve(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans=solve(n-1,coins,amount,dp);

        return ans>=1e9?-1:ans;
    }
};