class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int val=0;

        for(int num:nums){
            val=(val*2+num)%5;

            ans.push_back(val==0);
        }
        return ans;
    }
};