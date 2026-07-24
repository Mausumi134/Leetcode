class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int i=0;
        unordered_map<char,int>mp;
        for(int j=0;j<n;j++){
           mp[s[j]]++;
           while(mp[s[j]]>1){
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            i++;
            
           }
           maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};