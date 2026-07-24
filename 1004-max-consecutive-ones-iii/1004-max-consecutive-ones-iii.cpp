class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int maxlen=0;
        int zerocount=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0)zerocount++;
            while(zerocount>k){
                if(nums[i]==0)zerocount--;
                 i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
        
    }
};