class Solution {
public:
    vector<vector<int>>result;
    void solve(int i,vector<int>& candidates,int target,vector<int>& ans){
        if(i==candidates.size())return;
        if(target==0){
            result.push_back(ans);
            return;
        }

        solve(i+1,candidates,target,ans);
        if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        solve(0,candidates,target,ans);
        return result;
    }
};