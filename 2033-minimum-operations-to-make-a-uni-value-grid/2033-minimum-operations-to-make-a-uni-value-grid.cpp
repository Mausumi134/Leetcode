class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int>arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
         
         int remainder=arr[0]%x;

        for(int i=1;i<arr.size();i++){
            if(remainder!= arr[i]%x){
                return -1;
            }
        }

        int median=arr[arr.size()/2];

        int total=0;

        for(int n:arr){
            total+=abs(median-n)/x;
        }
        return total;
    }
};