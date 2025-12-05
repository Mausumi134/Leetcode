class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        return totalSum % 2 == 0 ? nums.size() - 1 : 0;
    }
};