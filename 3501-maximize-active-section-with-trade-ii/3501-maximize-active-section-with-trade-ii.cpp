class SegmentTree {
private:
    int n;
    vector<int> arr;
    vector<int> seg;

    void build(int p, int l, int r) {
        if (l == r) {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int _query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return seg[p];
        }

        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = max(res, _query(p << 1, l, mid, L, R));
        }
        if (R > mid) {
            res = max(res, _query(p << 1 | 1, mid + 1, r, L, R));
        }

        return res;
    }

public:
    SegmentTree(const vector<int>& arr) : arr(arr) {
        n = arr.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }

    int query(int L, int R) {
        if (L > R) {
            return 0;
        }

        return _query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        vector<int> blockLeft;
        vector<int> blockRight;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i += 1;
            }
            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }

        int m = zeroBlocks.size();
        if (m < 2) {  // continuous 0 blocks less than 2 segments, return the
                      // answer directly
            return vector<int>(queries.size(), cnt1);
        }

        vector<int> tmpSum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }
        SegmentTree seg(tmpSum);
        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
                    blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
                    blockLeft.begin() - 1;

            // at most 1 continuous block of 0s within the substring
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }
            int firstLen = blockRight[i] - max(blockLeft[i], l) +
                           1;  // actual length of the first consecutive block
                               // of 0s in the substring
            int lastLen = min(blockRight[j], r) - blockLeft[j] +
                          1;  // actual length of the last consecutive block of
                              // 0s in the substring
            // exactly 2 consecutive 0 blocks within the substring
            if (i + 1 == j) {
                int bestGain = firstLen + lastLen;
                ans.push_back(cnt1 + bestGain);
                continue;
            }

            int val1 = firstLen + zeroBlocks[i + 1];
            int val2 = zeroBlocks[j - 1] + lastLen;
            int val3 = seg.query(i + 1, j - 2);
            int bestGain = max({val1, val2, val3});
            ans.push_back(cnt1 + bestGain);
        }

        return ans;
    }
};