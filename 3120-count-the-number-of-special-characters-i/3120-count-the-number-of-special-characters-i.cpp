class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
       unordered_set<char>st;
       for(char c:word){
        st.insert(c);
       }
        for(char c:word){
           if(islower(c)){
              char p=toupper(c);
              if(st.find(p)!=st.end()){
                count++;
                st.erase(c);
                st.erase(p);
              }
           }
           else if(isupper(c)){
               char p=tolower(c);
              if(st.find(p)!=st.end()){
                count++;
                st.erase(c);
                st.erase(p);
              }
           }
          
        }
        return count;
    }
};