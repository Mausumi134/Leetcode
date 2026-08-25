class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=k;

        while(st.count(ans)){
            ans+=k;
        }
        return ans;
    }
};