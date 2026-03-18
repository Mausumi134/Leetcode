class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=1;
        int n=nums.size();
         vector<int>ans(n);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
               ans[pos]=nums[i];
               pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};