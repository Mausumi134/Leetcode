class Solution {
public:
    bool solve(int i,vector<int>& nums,vector<vector<int>>& dp,int target){
        if(i==0)return nums[i]==target;

        if(dp[i][target]!=-1)return dp[i][target];

        int nottake=solve(i-1,nums,dp,target);

        int take=false;

        if(nums[i]<=target){
            take=solve(i-1,nums,dp,target-nums[i]);
        }
       return dp[i][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;

        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return solve(n-1,nums,dp,target);
    }
};