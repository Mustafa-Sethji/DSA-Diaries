# Minimum Operations to Sort a Permutation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers from 0 to `n - 1`.

You may perform **only** the following operations:

- Reverse the entire array.
- Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the **minimum** number of operations required to sort the array in **increasing** order. If it is **not possible** to sort the array using only the given operations, return -1.

 

**Example 1:**

**Input:** nums = [0,2,1]

**Output:** 2

**Explanation:**

- Rotate Left by one: [2, 1, 0]
- Reverse the array: [0, 1, 2]

The array becomes sorted in 2 operations, which is minimal

**Example 2:**

**Input:** nums = [1,0,2]

**Output:** 2

**Explanation:**

- Reverse the array: [2, 0, 1]
- Rotate Left by one: [0, 1, 2]

The array becomes sorted in 2 operations, which is minimal.

**Example 3:**

**Input:** nums = [2,0,1,3]

**Output:** -1

**Explanation:**

It is impossible to reach `[2, 0, 1, 3]`. Thus, the answer is -1.

 

**Constraints:**

- 1 <= n == nums.length <= 105
- 0 <= nums[i] <= n - 1
- nums is a permutation of integers from 0 to n - 1.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 63.39%)  
**Memory:** 141.4 MB (beats 87.80%)  
**Submitted:** 2026-10-22T10:52:37.485Z  

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/)