class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size(), prev = 0;

        for (int i = 0; i < n; i += k) {
            int cnt = 0;
            int mini = nums[i], maxi = nums[i];

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] > nums[j + 1])
                    cnt++;

                mini = min(mini, nums[j + 1]);
                maxi = max(maxi, nums[j + 1]);
            }

            if (nums[i + k - 1] > nums[i])
                cnt++;

            if (cnt > 1 || prev > mini)
                return false;

            prev = maxi;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                if (check(nums, k))
                    ans += k;

                if (k * k != n && check(nums, n / k))
                    ans += n / k;
            }
        }

        return ans;
    }
};