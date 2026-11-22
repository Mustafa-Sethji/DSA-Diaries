# Q1. Count Dominant Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums`.

An element in `nums` is called **dominant** if it is **greater than or equal to** the average of its immediate neighbors.

The immediate neighbors of `nums[i]` are `nums[i - 1]` and `nums[i + 1]`, when those indices exist.

A single element with no neighbors is considered **dominant**.

Return the number of **dominant** elements in `nums`.

 

Original
C++
**Example 1:**

**Input:** nums = [1,10,2]

**Output:** 1

**Explanation:**

- For nums[0] = 1, its only neighbor is 10. Since 1 < 10, it is not dominant.
- For nums[1] = 10, its neighbors are 1 and 2. Their average is (1 + 2) / 2 = 1.5. Since 10 > 1.5, it is dominant.
- For nums[2] = 2, its only neighbor is 10. Since 2 < 10, it is not dominant.

Therefore, the answer is 1.

**Example 2:**

**Input:** nums = [6,4,2]

**Output:** 2

**Explanation:**

- For nums[0] = 6, its only neighbor is 4. Since 6 > 4, it is dominant.
- For nums[1] = 4, its neighbors are 6 and 2. Their average is (6 + 2) / 2 = 4. Since 4 = 4, it is dominant.
- For nums[2] = 2, its only neighbor is 4. Since 2 < 4, it is not dominant.

Therefore, the answer is 2.

**Example 3:**

**Input:** nums = [7]

**Output:** 1

**Explanation:**

- For nums[0] = 7, it has no neighbors, so it is dominant.

Therefore, the answer is 1.

 

**Constraints:**

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 30.7 MB (beats 100.00%)  
**Submitted:** 2026-11-22T02:38:44.431Z  

```cpp
class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int dom=0;
        int n=nums.size();
        if(n==1)return 1;
        for(int i=0;i<nums.size();i++){
            if(i==0 || i==n-1){
                if(i==0 && nums[i]>=nums[i+1])dom++;
                if(i==n-1 && nums[n-1]>=nums[n-2])dom++;
            }
            else if (2*nums[i]>=(nums[i-1]+nums[i+1]))dom++;
        }
        return dom;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-dominant-elements/)