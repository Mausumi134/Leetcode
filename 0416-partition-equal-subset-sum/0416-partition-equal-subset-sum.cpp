class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int s=1;s<=target;s++){
                bool nottake=dp[i-1][s];
                bool take=false;
                if(nums[i]<=s){
                  take=dp[i-1][s-nums[i]];
                }
                dp[i][s]=take||nottake;
            }
        }

        return dp[n-1][target];
    }
};