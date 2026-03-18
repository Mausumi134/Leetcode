class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int>& c, vector<int>& ans, int target){
        if(target == 0){
            result.push_back(ans);
            return;
        }

        for(int j = i; j < c.size(); j++){

            // skip duplicates
            if(j > i && c[j] == c[j-1]) continue;

            if(c[j] > target) break;

            ans.push_back(c[j]);
            solve(j+1, c, ans, target - c[j]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        solve(0, candidates, ans, target);
        return result;
    }
};
