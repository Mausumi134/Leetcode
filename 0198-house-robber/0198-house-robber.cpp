class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i<0)return 0;

        if(dp[i]!=-1)return dp[i];

        int nottake=solve(i-1,nums,dp);
        int take=nums[i]+solve(i-2,nums,dp);

        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};