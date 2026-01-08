class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int a=0;
       sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++){
        if(nums[i]==a)a++;
        else return i;
     }
     return a;
    }
};