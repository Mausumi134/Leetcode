class Solution {
public:
    vector<string>result;
    void solve(int i,int n,string ans,int open,int close){
        if(i==2*n){
            result.push_back(ans);
            return;
        }

        if(open<n)solve(i+1,n,ans+'(',open+1,close);
        if(close<open)solve(i+1,n,ans+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
      solve(0,n,"",0,0);
      return result;  
    }
};