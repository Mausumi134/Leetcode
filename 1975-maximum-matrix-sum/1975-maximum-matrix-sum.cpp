class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minval=INT_MAX;
        int count=0;
         long long ans=0;
        int n=matrix.size(),m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    count++;
                }
                int num=abs(matrix[i][j]);
                sum+=num;
                if(minval>num){
                    minval=num;
                }
            }
        }

        if(count%2==0){
            ans+=sum;
        }
        else{
            ans+=sum-2*minval;
        }

        return ans;
    }
};