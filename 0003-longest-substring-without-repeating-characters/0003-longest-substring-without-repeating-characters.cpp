class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxi=0;
       int i=0;
       int n=s.size();
       int unique=0;
       unordered_map<char,int>mp;
       for(int j=0;j<n;j++){
         if(mp[s[j]]==0)unique++;
         mp[s[j]]++;
         while(mp[s[j]]>1){
            mp[s[i]]--;
            if(mp[s[i]]==0)unique--;
            i++;
         }
         maxi=max(maxi,j-i+1);
       }
      return maxi;
    }
};