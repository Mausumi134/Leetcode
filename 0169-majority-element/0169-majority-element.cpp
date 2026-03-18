class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==temp){
                count++;
            }
            else{
                if(count<=0){
                    temp=nums[i];
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return temp;
    }
};