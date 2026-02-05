class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            int leftsum,rightsum;
            if(i==0){
               leftsum=0;
               rightsum=nums[n-1]-nums[i];
            }
            else if(i==n-1){
                leftsum=nums[i-1];
                rightsum=0;
            }
            else{
                leftsum=nums[i-1];
                rightsum=nums[n-1]-nums[i];
            }

            if(leftsum==rightsum){
                return i;
            }
        }
        return -1;
    }
};
