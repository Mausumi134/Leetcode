class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>arr(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    arr[i][j]=1;
                }
                else if(grid[i][j]=='Y'){
                    arr[i][j]=-1;
                }
            }
        }

        vector<vector<int>>prefix(n,vector<int>(m,0));
        vector<vector<int>>xcount(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=(grid[i][j]=='X')?1:0;
                int top=(i>0)?xcount[i-1][j]:0;
                int left=(j>0)?xcount[i][j-1]:0;
                int diag=(i>0 && j>0)?xcount[i-1][j-1]:0;

                xcount[i][j]=val+top+left-diag;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                int top=(i>0)?prefix[i-1][j]:0;
                int left=(j>0)?prefix[i][j-1]:0;
                int diag=(i>0 && j>0)?prefix[i-1][j-1]:0;

                prefix[i][j]=arr[i][j]+top+left-diag;
            }
        }

        int count=0;
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                if(prefix[i][j]==0 && xcount[i][j]>=1){
                    count++;
                }
            }
        }
        return count;
    }
};