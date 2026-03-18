class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
             dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int ascs1=0,ascs2=0;

        for(char c:s1){
            ascs1+=int(c);
        }
        for(char c:s2){
            ascs2+=int(c);
        }

        int ans=ascs1+ascs2-2*dp[n][m];
        return ans;
    }
};