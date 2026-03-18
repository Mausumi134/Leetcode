class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        long long sum=0;
        long long maxsum=LLONG_MIN;

        while(r<n){
            sum+=nums[r];

            if(r-l+1==k){
                maxsum=max(maxsum,sum);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (double)maxsum/k;
    }
};