class Solution {
public:
    string removeDuplicates(string s) {
        string res="";

        stack<char>st;

        for(char c:s){
            
            if(!st.empty() && st.top()==c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

       while(!st.empty()){
           res+=st.top();
           st.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};