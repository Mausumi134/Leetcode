class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=k-1;
        int mini=INT_MAX;
        while(j<n){
           mini=min(mini,nums[j]-nums[i]);
           i++;
           j++;
        }
        return mini;
    }
};