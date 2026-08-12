class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int maxlen=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;

            while(mp[nums[j]]>k){
            mp[nums[i]]--;
               if(mp[nums[i]]==0)mp.erase(nums[i]);
               i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }

};