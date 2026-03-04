class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>a(n,0),b(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    a[i]++;
                    b[j]++;
                }
            }
        }

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] && a[i]==1 && b[j]==1){
                    count++;
                }
            }
        }
     return count;
    }
};