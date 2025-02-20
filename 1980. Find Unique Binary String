class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> integers;
        for (string num : nums) {
            integers.insert(stoi(num, 0, 2));
        }
        
        int ans = stoi(nums[0], 0, 2);
        int n = nums.size();
        
        while (integers.find(ans) != integers.end()) {
            ans = rand() % (int) pow(2, n);
        }
        
        return bitset<16>(ans).to_string().substr(16 - n);
    }
};