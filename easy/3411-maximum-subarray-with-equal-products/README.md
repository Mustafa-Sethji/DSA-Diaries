# Maximum Subarray With Equal Products

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of **positive** integers `nums`.

An array `arr` is called **product equivalent** if `prod(arr) == lcm(arr) * gcd(arr)`, where:

- prod(arr) is the product of all elements of arr.
- gcd(arr) is the GCD of all elements of arr.
- lcm(arr) is the LCM of all elements of arr.

Return the length of the **longest** **product equivalent** subarray of `nums`.

 

Original
C++
**Example 1:**

**Input:** nums = [1,2,1,2,1,1,1]

**Output:** 5

**Explanation:** 

The longest product equivalent subarray is `[1, 2, 1, 1, 1]`, where `prod([1, 2, 1, 1, 1]) = 2`, `gcd([1, 2, 1, 1, 1]) = 1`, and `lcm([1, 2, 1, 1, 1]) = 2`.

**Example 2:**

**Input:** nums = [2,3,4,5,6]

**Output:** 3

**Explanation:** 

The longest product equivalent subarray is `[3, 4, 5].`

**Example 3:**

**Input:** nums = [1,2,3,1,4,5,1]

**Output:** 5

 

**Constraints:**

- 2 <= nums.length <= 100
- 1 <= nums[i] <= 10

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 72.03%)  
**Memory:** 28.1 MB (beats 18.33%)  
**Submitted:** 2026-11-24T18:23:10.081Z  

```cpp
class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {

        int n = nums.size();
        int maxLen = 0;

        // gcd <= 10 and lcm <= lcm(1..10) = 2520, so gcd * lcm <= 25200.
        const int LIMIT = 25200;

        for (int i = 0; i < n; i++) {

            int l = 1;
            int g = 0;
            int prd = 1;

            for (int j = i; j < n; j++) {

                int num = nums[j];

                prd *= num;

                // The product only grows, so it can never come back down to g * l.
                if (prd > LIMIT) {
                    break;
                }

                g = gcd(g, num);
                l = (l * num) / gcd(l, num);

                if (prd == g * l) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-subarray-with-equal-products/)