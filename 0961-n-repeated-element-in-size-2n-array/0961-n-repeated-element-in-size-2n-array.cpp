class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;

        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans;
        for(auto it:mp){
           if(it.second==n){
               ans=it.first;
           }
        }
        return ans;
    }
};