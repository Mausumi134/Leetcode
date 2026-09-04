class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxarr(n);
        vector<int>minarr(n);

        int maxi=nums[0];
        int mini=nums[n-1];
        maxarr[0]=nums[0];
        minarr[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            maxi=max(nums[i],maxi);
            maxarr[i]=maxi;
        }

        for(int i=n-2;i>=0;i--){
            mini=min(mini,nums[i]);
            minarr[i]=mini;
        }


        for(int i=0;i<n;i++){
            int diff=maxarr[i]-minarr[i];
            if(diff<=k)return i;
        }
        return -1;
    }
};