class Solution {
public:
    int longestBalanced(string s) {
        vector<int>freq(26);
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            fill(freq.begin(),freq.end(),0);
            for(int j=i;j<n;j++){
                bool flag=true;
                int c=s[j]-'a';
                freq[c]++;
                for(auto x:freq){
                    if(x>0 && x!=freq[c]){
                        flag=false;
                        break;
                    }
                }
               if(flag){
                res=max(res,j-i+1);
               }
            }
        }
        return res;
    }
};