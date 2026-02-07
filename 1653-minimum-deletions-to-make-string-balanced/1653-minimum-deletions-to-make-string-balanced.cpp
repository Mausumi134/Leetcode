class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count=0;
        for(char c:s){
            if(!st.empty() && st.top()=='b' && c=='a'){
                st.pop();
                count++;
            }
            else{
                st.push(c);
            }
        }
        return count;
    }
};