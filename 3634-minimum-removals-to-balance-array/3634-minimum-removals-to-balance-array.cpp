class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
         int best=1;
        while(i<n){
            long long ans=(long long)nums[i]*k;

            while(j<n && nums[j]<=ans){
                j++;
                best=max(best,j-i);
            }
            i++;
      }

      return n-best;
    }
};