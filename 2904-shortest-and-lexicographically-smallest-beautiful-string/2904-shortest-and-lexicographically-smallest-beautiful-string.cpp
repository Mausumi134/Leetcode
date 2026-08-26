class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int n=s.size();
        int minlen=INT_MAX;
        string minstring="";
        int count=0;
        for(int j=0;j<n;j++){
            if(s[j]=='1')count++;

            while(count>k){
                if(s[i]=='1')count--;
                i++;
            }
            while(i<=j && count==k){
                int len=j-i+1;
                if(len<minlen){
                    minlen=len;
                    minstring=s.substr(i,len);
                }
                else if(len==minlen){
                    string curr=s.substr(i,len);
                    if(curr<minstring)minstring=curr;
                }
                if (s[i] == '1') count--;
                i++;
            }
        }
        return minstring;
    }
};