class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * 1LL * nums[i];
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                ans += nums[n - 1 - i];
            } else {
                ans -= nums[n - 1 - i];
            }
        }

        return ans;
    }
};

