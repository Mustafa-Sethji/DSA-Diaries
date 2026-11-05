
class Fenwick {
public:
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }

    // Find the position of the kth smallest element
    int kth(long long k) {
        int idx = 0;

        for (int pw = 1 << 17; pw > 0; pw >>= 1) {
            int next = idx + pw;

            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
        }

        return idx + 1;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());

        vals.erase(
            unique(vals.begin(), vals.end()),
            vals.end()
        );

        int m = vals.size();

        Fenwick bitCount(m);
        Fenwick bitSum(m);

        // Get compressed index
        auto getIndex = [&](int v) {
            return lower_bound(
                vals.begin(), vals.end(), v
            ) - vals.begin() + 1;
        };

        // Calculate cost of every window
        vector<long long> cost(n - x + 1);

        long long windowSum = 0;

        // Insert first window
        for (int i = 0; i < x; i++) {
            int id = getIndex(nums[i]);

            bitCount.update(id, 1);
            bitSum.update(id, nums[i]);

            windowSum += nums[i];
        }

        for (int i = 0; i <= n - x; i++) {

            // Find median (lower median)
            int medianId = bitCount.kth((x + 1) / 2);

            long long median = vals[medianId - 1];

            // Count and sum of elements <= median
            long long cnt = bitCount.query(medianId);
            long long sum = bitSum.query(medianId);

            // Calculate cost
            long long leftCost = median * cnt - sum;

            long long rightCost =
                (windowSum - sum) -
                median * (x - cnt);

            cost[i] = leftCost + rightCost;

            // Remove outgoing element
            if (i + x < n) {

                int oldId = getIndex(nums[i]);

                bitCount.update(oldId, -1);
                bitSum.update(oldId, -nums[i]);

                windowSum -= nums[i];

                // Add incoming element
                int newId = getIndex(nums[i + x]);

                bitCount.update(newId, 1);
                bitSum.update(newId, nums[i + x]);

                windowSum += nums[i + x];
            }
        }

        // Dynamic Programming
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Option 1: Skip current element
                curr[i] = curr[i - 1];

                // Option 2: Select window of size x
                if (i >= x && prev[i - x] != INF) {

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
