class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        return (long long)k*(maxi-mini);
    }
};