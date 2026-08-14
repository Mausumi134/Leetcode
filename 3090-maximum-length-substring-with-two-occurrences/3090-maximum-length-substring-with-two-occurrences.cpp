class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int maxlength=0;
        unordered_map<char,int>mp;
        for(int j=0;j<s.size();j++){
           mp[s[j]]++;

           while(mp[s[j]]>2){
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            i++;
           }

           maxlength=max(maxlength,j-i+1);
        }
        return maxlength;
    }
};