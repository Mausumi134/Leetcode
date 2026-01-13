class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;

        for(int num:nums){
            sum+=num;
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
    }
};