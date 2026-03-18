class Solution {
public:
    int mono(const string& s){
        if(s.empty()) return 0;
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < (int)s.size(); i ++){
            if(s[i] == s[i - 1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }

    int duo(const string& s, char c1, char c2){
        map<int, int> pos;
        pos[0] = -1;
        int ans = 0;
        int delta = 0;
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] != c1 && s[i] != c2){
                pos.clear();
                pos[0] = i;
                delta = 0;
                continue;
            }
            if(s[i] == c1){
                delta++;
            }
            else{
                delta--;
            }
            if(pos.find(delta) != pos.end()){
                ans = max(ans, i - pos[delta]);
            }
            else{
                pos[delta] = i;
            }
        }
        return ans;
    }

    int trio(const string& s){
        vector<int> cnt(3, 0);

        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;

        int ans = 0;

        for(int i = 0; i < (int)s.size(); i++){
            cnt[s[i] - 'a']++;

            vector<int> key = {cnt[1] - cnt[0], cnt[2] - cnt[0]};

            if(pos.find(key) != pos.end()){
                ans = max(ans, i - pos[key]);
            }
            else{
                pos[key] = i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        return max({
            mono(s),
            duo(s, 'a', 'b'),
            duo(s, 'a', 'c'),
            duo(s, 'b', 'c'),
            trio(s)
        });
    }
};