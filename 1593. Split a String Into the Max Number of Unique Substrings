class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) return 0;

        int maxCount = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                seen.erase(substring);
            }
        }
        return maxCount;
    }
};