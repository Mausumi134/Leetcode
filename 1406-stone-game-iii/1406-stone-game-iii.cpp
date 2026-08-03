class Solution {
public:
    static constexpr int MIN = -50000001;
    static inline string s[] = {"Bob", "Tie", "Alice"};

    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, MIN);

        auto maxDiff = [&](this auto&& maxDiff, int i) -> int {
            if (i == n) return 0;

            int& res = dp[i];
            if (res != MIN) return res;

            int a = MIN, b = MIN, c = MIN;

            if (i < n)
                a = A[i] - maxDiff(i + 1);
            if (i + 1 < n)
                b = A[i] + A[i + 1] - maxDiff(i + 2);
            if (i + 2 < n)
                c = A[i] + A[i + 1] + A[i + 2] - maxDiff(i + 3);

            res = max(a, max(b, c));
            return res;
        };

        int d = maxDiff(0);
        return s[(d > 0) - (d < 0) + 1];
    }
};