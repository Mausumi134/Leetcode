class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[i]=nums[(i+nums[i])%n];
            }
            else if(nums[i]<0){
                res[i]=nums[((i+nums[i])%n+n)%n];
            }
            else{
                res[i]=nums[i];
            }
        }
        return res;
    }
};