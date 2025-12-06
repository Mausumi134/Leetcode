class Solution {
public:
    long long mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>dp(n+1);
        vector<long long>prefix(n+1);

        deque<int>minq,maxq;

        dp[0]=1,prefix[0]=1;

        int left=0;

        for(int right=0;right<n;right++){
            while(!maxq.empty() && nums[maxq.back()]<=nums[right]){
                maxq.pop_back();
            }
            maxq.push_back(right);
            while(!minq.empty() && nums[minq.back()]>=nums[right]){
                minq.pop_back();
            }
            minq.push_back(right);

            while(!maxq.empty() && !minq.empty() && nums[maxq.front()]-nums[minq.front()]>k){
                if(maxq.front()==left)maxq.pop_front();
                if(minq.front()==left)minq.pop_front();

                left++;
            }

            long ways=prefix[right];

            if(left>0) ways=(ways-prefix[left-1]+mod)%mod;

            dp[right+1]=ways;
            prefix[right+1]=(prefix[right]+dp[right+1])%mod;
        }

        return (int)dp[n];
    }
};