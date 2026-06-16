class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char c:s){
            if(c=='*'){
                if (!result.empty()) {
                  result.pop_back();
                }
            }
            else if(c=='#'){
                result=result+result;
            }
            else if(c=='%'){
                reverse(result.begin(),result.end());
            }
            else{
                result+=c;
            }
        }
        return result;
    }
};