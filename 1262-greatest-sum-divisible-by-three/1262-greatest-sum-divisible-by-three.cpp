class Solution {
public:
    const int NEG = -1000000000;
    int maxsum(vector<int>& nums,int i,int rem,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n){
            return (rem==0)?0:NEG;

        }

        if(dp[i][rem]!=INT_MIN)return dp[i][rem];

        int ans=maxsum(nums,i+1,rem,dp);

        int newrem=(rem+nums[i]%3)%3;
        int take=maxsum(nums,i+1,newrem,dp);

        if(take>NEG)ans=max(ans,take+nums[i]);

        dp[i][rem]=ans;
        return ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(3,INT_MIN));

        int res=maxsum(nums,0,0,dp);
        return max(0,res);
    }
};