class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = n;
        for (int i = 0; i <= 4; i++)
            mask |= mask >> (1 << i);
        return ~n & mask;
    }
};