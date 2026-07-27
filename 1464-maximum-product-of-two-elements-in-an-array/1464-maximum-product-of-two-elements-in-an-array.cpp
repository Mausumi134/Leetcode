class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=nums[0];
        int second=0;


        for(int i=1;i<nums.size();i++){
            if(nums[i]>first){
                second=first;
                first=nums[i];
            }
            else if(nums[i]<=first && nums[i]>second){
                second=nums[i];
            }
        }
        return (first-1)*(second-1);
    }
};