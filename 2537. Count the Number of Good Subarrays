class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        long long pairCount = 0, goodSubarrays = 0;

        for (int right = 0; right < nums.size(); ++right) {
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            while (pairCount >= k) {
                goodSubarrays += nums.size() - right;
                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }
        }

        return goodSubarrays;
    }
};