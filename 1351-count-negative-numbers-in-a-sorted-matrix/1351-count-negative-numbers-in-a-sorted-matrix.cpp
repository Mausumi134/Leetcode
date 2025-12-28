class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0,n=grid.size(),m=grid[0].size(),i=0,j=m-1;

        while(j>=0 && i<n){
            if(grid[i][j]>=0){
                i++;
            }
            else{
                count+=n-i;
                j--;
            }
        }
        return count;
    }
};