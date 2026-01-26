class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;

        unordered_map<int,int>mp;

        for(int num:nums){
            mp[num]++;
        }
        int ans;
        for(auto i:mp){
          if(i.second==n){
            ans=i.first;
          }
        }
        return ans;
    }
};