class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxi=max(maxi,temp);
                temp=0;
            }
            else{
                temp++;
            }
        }
        maxi=max(maxi,temp);
        return maxi;
    }
};