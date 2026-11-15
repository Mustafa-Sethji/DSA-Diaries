# Number of Sub-arrays With Odd Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `arr`, return *the number of subarrays with an **odd** sum*.

Since the answer can be very large, return it modulo `109 + 7`.

 

Original
C++
**Example 1:**

```
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

```

**Example 2:**

```
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

```

**Example 3:**

```
Input: arr = [1,2,3,4,5,6,7]
Output: 16

```

 

**Constraints:**

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 17.51%)  
**Memory:** 117.4 MB (beats 15.58%)  
**Submitted:** 2026-11-15T18:46:06.499Z  

```cpp
//Approach-3 (Optimal using prefix-sum array)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for(int i = 0; i < n; i++) {
            if(prefix[i]%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)