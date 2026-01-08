class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1e9));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int take=nums1[i]*nums2[j]+max(0,dp[i+1][j+1]);
                int skipA=dp[i+1][j];
                int skipB=dp[i][j+1];

                dp[i][j]=max(take,max(skipA,skipB));
            }
        }
        return dp[0][0];
    }
};