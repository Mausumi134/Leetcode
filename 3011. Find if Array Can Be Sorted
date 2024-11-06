class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>mm;
        mm.push_back({nums[0],nums[0]});
        for(int i = 1 ; i < nums.size() ;i++)
        {
            int cur = __builtin_popcount(nums[i]);
            int prev = __builtin_popcount(nums[i-1]);
            if(cur != prev)
            {   
                mm.push_back({nums[i],nums[i]});
            }
            mm.back().first = min(mm.back().first,nums[i]);
            mm.back().second = max(mm.back().second,nums[i]);
        }
        for(int i = 1 ; i < mm.size() ; i++)
        {
            if(mm[i-1].second > mm[i].first)
                return false;
        }
        return true;
    }
};