// C++ Solution
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, int> counter;
        for (int num : nums) counter[num]++;
        vector<int> comb;
        backtrack(counter, comb, nums.size(), results);
        return results;
    }
    void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int N,
                   vector<vector<int>>& results) {
        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }
        for (auto& item : counter) {
            int num = item.first;
            int count = item.second;
            if (count == 0) continue;
            comb.push_back(num);
            counter[num]--;
            backtrack(counter, comb, N, results);
            comb.pop_back();
            counter[num]++;
        }
    }
};