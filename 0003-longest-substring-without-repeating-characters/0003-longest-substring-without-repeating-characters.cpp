class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            for(int j=i;j<n;j++){
                if(st.count(s[j])){
                    break;
                }
                st.insert(s[j]);
                 maxlen=max(maxlen,j-i+1);
            }
          
        }
        return maxlen;
    }
};