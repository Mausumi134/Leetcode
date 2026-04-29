class Solution {
public:
    bool isPal(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.size();

            for (int k = 0; k <= n; k++) {

              
                if (isPal(word, 0, k - 1)) {
                    string right = word.substr(k);
                    reverse(right.begin(), right.end());

                    if (mp.count(right) && mp[right] != i) {
                        ans.push_back({mp[right], i});
                    }
                }

                
                if (k != n && isPal(word, k, n - 1)) {
                    string left = word.substr(0, k);
                    reverse(left.begin(), left.end());

                    if (mp.count(left) && mp[left] != i) {
                        ans.push_back({i, mp[left]});
                    }
                }
            }
        }

        return ans;
    }
};