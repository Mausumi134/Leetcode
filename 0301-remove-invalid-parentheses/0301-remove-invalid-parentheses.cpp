class Solution {
public:
    unordered_set<string> ans;

    void solve(string& s, int index, int balance,int leftRem, int rightRem, string curr) {

     
        if (balance < 0)
            return;

        if (index == s.size()) {
            if (balance == 0 && leftRem == 0 && rightRem == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        if (ch != '(' && ch != ')') {
            solve(s, index + 1, balance,
                  leftRem, rightRem, curr + ch);
            return;
        }

  
        if (ch == '(') {

      
            if (leftRem > 0) {
                solve(s, index + 1, balance,
                      leftRem - 1, rightRem, curr);
            }

            solve(s, index + 1, balance + 1,
                  leftRem, rightRem, curr + ch);
        }

        else {

            if (rightRem > 0) {
                solve(s, index + 1, balance,
                      leftRem, rightRem - 1, curr);
            }

     
            if (balance > 0) {
                solve(s, index + 1, balance - 1,
                      leftRem, rightRem, curr + ch);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {

                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        solve(s, 0, 0, leftRem, rightRem, "");

        return vector<string>(ans.begin(), ans.end());
    }
};