class Solution {
public:
    bool possible( vector<vector<int>>& pre,int k,int threshold){
        int m=pre.size();
        int n=pre[0].size();
        for(int i=k;i<m;i++){
            for(int j=k;j<n;j++){
                int sum=pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k];
                if(sum<=threshold)return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>pre(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        int l=1,r=min(m,n),ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(pre,mid,threshold)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};