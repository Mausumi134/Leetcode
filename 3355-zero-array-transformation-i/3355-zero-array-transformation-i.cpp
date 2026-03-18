class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);

        for(auto &q:queries){
            int l=q[0];
            int r=q[1];

            diff[l]+=1;

            if(r+1<n)diff[r+1]-=1;
        }
        int cumsum=0;
        vector<int>res;

        for(int i=0;i<n;i++){
            cumsum+=diff[i];
            res.push_back(cumsum);
        }
        for(int i=0;i<n;i++){
            if(res[i]<nums[i])return false;
        }
        return true;
    }
};