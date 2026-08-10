class Solution {
public:
    static constexpr int MAX = 100000;
    inline static bitset<MAX + 1> dp;

    inline static bool init = []() {
        for (int i = 0; i <= MAX; i++) {
            if (dp.test(i)) continue;
            for (int j = 1; j * j <= MAX - i; j++)
                dp.set(i + j * j);
        }
        
        return false;
    }();

    bool winnerSquareGame(int n) { return dp.test(n); }
};