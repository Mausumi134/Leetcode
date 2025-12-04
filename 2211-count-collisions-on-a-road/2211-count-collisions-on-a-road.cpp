class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int count=0;


        for(char c:directions){
            if(c=='L'){
                if(!st.empty() && st.top()=='R'){
                    st.pop();
                    count+=2;
                    c='S';


                    while(!st.empty() && st.top()=='R'){
                        st.pop();
                        count+=1;
                    }
                }
            else if(!st.empty() && st.top()=='S'){
                count+=1;
                c='S';
            }
            else{
                continue;
            }
            }
            else if(c=='S'){
                while(!st.empty() && st.top()=='R'){
                    st.pop();
                    count+=1;
                }
            }
            if(c=='R' || c=='S'){
                st.push(c);
            }
        }
        return count;
    }
};