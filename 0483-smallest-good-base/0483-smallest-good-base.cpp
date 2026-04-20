class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (int i = 63; i >= 2; i--) {
            long long l = 2, h = num - 1;

            while (l <= h) {
                long long m = l + (h - l) / 2;

                long long sum = 1, x = 1;
                bool overflow = false;

                for (int j = 1; j < i; j++) {

                    // check before multiplication
                    if (x > num / m) {
                        overflow = true;
                        break;
                    }

                    x *= m;
                    sum += x;

                    if (sum > num) break;
                }

                if (sum == num) return to_string(m);
                else if (overflow || sum > num) h = m - 1;
                else l = m + 1;
            }
        }

        return to_string(num - 1);
    }
};