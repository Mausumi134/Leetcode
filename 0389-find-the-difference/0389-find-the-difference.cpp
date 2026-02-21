class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;

        for(char c:s){
            res^=c;
        }
        for(char c:t){
            res^=c;
        }

        return res;
    }
};