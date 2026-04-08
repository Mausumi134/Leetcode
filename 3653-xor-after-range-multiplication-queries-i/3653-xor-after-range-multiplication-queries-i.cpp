class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];

            for(int i=l;i<=r;i+=k){
                nums[i]=(1LL*nums[i]*v)%1000000007;
            }
        }
        int xori=0;

        for(int num:nums){
            xori^=num;
        }
        return xori;
    }
};