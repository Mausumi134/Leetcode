class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        while (--n) {
            result = (result + 1) | x;
        }

        return result;
    }
};