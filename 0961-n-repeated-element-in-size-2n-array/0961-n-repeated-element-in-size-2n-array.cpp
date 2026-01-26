class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int k=1;k<=3;k++){
            for(int i=0;i<nums.size()-k;i++){
                if(nums[i]==nums[i+k]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};