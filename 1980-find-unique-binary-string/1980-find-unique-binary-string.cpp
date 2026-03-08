class Solution {
public:
    unordered_set<string>st;
    void generate(int i,int n,string res){
        if(i==n){
            st.insert(res);
            return;
        }
        generate(i+1,n,res+'0');
        generate(i+1,n,res+'1');
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        generate(0,n,"");

        for(auto& s:nums){
            st.erase(s);
        }
        return *st.begin();
    }
};