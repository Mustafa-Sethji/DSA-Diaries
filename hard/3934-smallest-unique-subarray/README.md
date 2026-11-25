# Smallest Unique Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`.

Find the **minimum **length of a subarray that is **not** **identical** to any other **subarray** in `nums`.

Return an integer denoting the **minimum possible length** of such a **subarray**.

Two **subarrays** are considered identical if they have the same length and the same elements in corresponding positions.

 

Original
C++
**Example 1:**

**Input:** nums = [3,3,3]

**Output:** 3

**Explanation:**

- Subarrays of length 1: [3] → appears 3 times
- Subarrays of length 2: [3, 3] → appears 2 times
- Subarrays of length 3: [3, 3, 3] → appears once

The subarray `[3, 3, 3]` is unique, so the smallest unique subarray length is 3.

**Example 2:**

**Input:** nums = [2,1,2,3,3]

**Output:** 1

**Explanation:**

Subarrays of length 1:

- [2] → appears 2 times
- [1] → appears once
- [3] → appears 2 times
The subarray `[1]` is unique, so the smallest unique subarray length is 1.

**Example 3:**

**Input:** nums = [1,1,2,2,1]

**Output:** 2

**Explanation:**

Subarrays of length 1:

- [1] → appears 3 times
- [2] → appears 2 times

Subarrays of length 2:

- [1, 1] → appears once
- [1, 2] → appears once
- [2, 2] → appears once
- [2, 1] → appears once
There is at least one subarray of length 2 that is unique, so the smallest unique subarray length is 2.

 

**Constraints:**

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 854 ms (beats 60.46%)  
**Memory:** 371.8 MB (beats 59.30%)  
**Submitted:** 2026-11-25T17:14:48.305Z  

```cpp
//Approach (Binary search on answer + Sliding Window + Rolling Hash)
//T.C : O(n*logn)
//S.C : O(n) for map
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    // Binary exponentiation
    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> mp;

        ll p = findPower(base, size-1); //O(log(size))

        int i = 0;
        int j = 0;

        while(j < n) { //O(n)
            hash = (hash * base + nums[j]) % MOD;

            if(j-i+1 < size) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * nums[i])%MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for(auto &it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;

    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;

        int result = n;

        while(l <= r) { //log(n)
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};



```

---

[View on LeetCode](https://leetcode.com/problems/smallest-unique-subarray/)