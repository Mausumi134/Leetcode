class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabet(26,0);

        for(char c:sentence){
            alphabet[c-'a']++;
        }

        for(int num:alphabet){
            if(num==0){
                return false;
            }
        }
        return true;
    }
};