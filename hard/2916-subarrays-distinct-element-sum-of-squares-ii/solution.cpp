class Solution {
    static const int MOD = 1'000'000'007;

    struct SegmentTree {
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n) : n(n), sum(4 * n, 0),
            sq(4 * n, 0), lazy(4 * n, 0) {}

        void apply(int node, int l, int r, long long val) {
            long long len = r - l + 1;

            sq[node] = (sq[node] + 2 * val % MOD * sum[node] % MOD
                       + val * val % MOD * len) % MOD;

            sum[node] = (sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r) {
            if (l <= r) update(1, 0, n - 1, l, r);
        }

        long long getSquareSum() {
            return sq[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int l = last[nums[r]] + 1;

            st.update(l, r);
            last[nums[r]] = r;

            ans = (ans + st.getSquareSum()) % MOD;
        }

        return ans;
    }
};