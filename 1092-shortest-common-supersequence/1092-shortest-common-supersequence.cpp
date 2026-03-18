class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
               }
               else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }

        string lcs="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                lcs+=str1[i-1];
                 i--;
            }
            else{
                lcs+=str2[j-1];
                j--;
            }
        }

        while(i>0){
            lcs+=str1[i-1];
            i--;
        }
        while(j>0){
            lcs+=str2[j-1];
            j--;
        }

        reverse(lcs.begin(),lcs.end());
        return lcs;
    }
};