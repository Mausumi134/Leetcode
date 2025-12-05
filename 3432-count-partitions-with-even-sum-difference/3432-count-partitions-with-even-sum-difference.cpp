class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
          leftsum+=nums[i];
          int rightsum=sum-leftsum;

          int ans=abs(leftsum-rightsum);
          if(ans%2==0)count++;
        }
        return count;
    }
};