class Solution {
public:
    vector<vector<int>>result;
    void solve(int index,vector<int>& nums,vector<int>& ans){
        
           result.push_back(ans);
        

       for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])continue;
        ans.push_back(nums[i]);
        solve(i+1,nums,ans);
        ans.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int>ans;
    sort(nums.begin(),nums.end());
    solve(0,nums,ans);
      return result;  
    }
};