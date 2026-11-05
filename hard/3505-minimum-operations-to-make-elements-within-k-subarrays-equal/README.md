# Minimum Operations to Make Elements Within K Subarrays Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and two integers, `x` and `k`. You can perform the following operation any number of times (**including zero**):

- Increase or decrease any element of nums by 1.

Return the **minimum** number of operations needed to have **at least** `k` *non-overlapping subarrays* of size **exactly** `x` in `nums`, where all elements within each subarray are equal.

 

**Example 1:**

**Input:** nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

**Output:** 8

**Explanation:**

- Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
- Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
- Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.

**Example 2:**

**Input:** nums = [9,-2,-2,-2,1,5], x = 2, k = 2

**Output:** 3

**Explanation:**

- Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
- Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

 

**Constraints:**

- 2 <= nums.length <= 105
- -106 <= nums[i] <= 106
- 2 <= x <= nums.length
- 1 <= k <= 15
- 2 <= k * x <= nums.length

## Solution

**Language:** C++  
**Runtime:** 527 ms (beats 98.61%)  
**Memory:** 213.8 MB (beats 100.00%)  
**Submitted:** 2026-11-05T11:16:36.698Z  

```cpp

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

```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)