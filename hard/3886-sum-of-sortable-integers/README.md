# Sum of Sortable Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`.

An integer `k` is called **sortable** if `k` **divides** `n` and you can sort `nums` in **non-decreasing** order by sequentially performing the following operations:

- Partition nums into consecutive subarrays of length k.
- Cyclically rotate each subarray independently any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

 

**Example 1:**

**Input:** nums = [3,1,2]

**Output:** 3

**Explanation:**​​​​​​​

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
- Only k = 3 is sortable. Hence, the answer is 3.

**Example 2:**

**Input:** nums = [7,6,5]

**Output:** 0

**Explanation:**

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
- No k is sortable. Hence, the answer is 0.

**Example 3:**

**Input:** nums = [5,8]

**Output:** 3

**Explanation:**​​​​​​​

- For n = 2, possible divisors are 1 and 2.
- Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.

 

**Constraints:**

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 91.18%)  
**Memory:** 98.5 MB (beats 30.88%)  
**Submitted:** 2026-10-20T15:16:14.633Z  

```cpp
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, 1e9);
        vector<int> prefDrop(n, 0);

        for (int i = 0; i < n; i++)
            prefMax[i + 1] = max(prefMax[i], nums[i]);

        for (int i = n - 1; i >= 0; i--)
            suffMin[i] = min(nums[i], suffMin[i + 1]);

        for (int i = 1; i < n; i++)
            prefDrop[i] = prefDrop[i - 1] +
                          (nums[i - 1] > nums[i]);

        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = prefDrop[end] - prefDrop[start];

                if (nums[end] > nums[start])
                    drops++;

                if (drops > 1 || prefMax[start] > suffMin[start])
                    return false;
            }
            return true;
        };

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k == 0) {
                if (check(k))
                    ans += k;

                int other = n / k;

                if (other != k && check(other))
                    ans += other;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-sortable-integers/)