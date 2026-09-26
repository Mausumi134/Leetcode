class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        string result = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                int j = i + 1;

                while(s[j] != ')') {
                    j++;
                }

                string key = s.substr(i + 1, j - i - 1);

                if(mp.find(key) != mp.end()) {
                    result += mp[key];
                }
                else {
                    result += "?";
                }

                i = j;
            }
            else {
                result += s[i];
            }
        }

        return result;
    }
};