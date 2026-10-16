# Subarrays Distinct Element Sum of Squares II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a **0-indexed **integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:

- Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].

Return *the sum of the **squares** of **distinct counts** of all subarrays of *`nums`.

Since the answer may be very large, return it **modulo** `109 + 7`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

 

**Example 1:**

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

```

**Example 2:**

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

 

**Constraints:**

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 399 ms (beats 33.77%)  
**Memory:** 299.5 MB (beats 5.19%)  
**Submitted:** 2026-10-16T12:19:23.964Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)