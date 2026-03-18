class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n-1 && nums[i]<nums[i+1]){
          i++;
        }
        if(i==0 || i==n-1){
            return false;
        }
        int pivotindex=i;

        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }
        if(i==pivotindex || i==n-1){
            return false;
        }
        while(i<n-1 && nums[i]<nums[i+1]){
          i++;
        }
        return i==n-1;
    }
};