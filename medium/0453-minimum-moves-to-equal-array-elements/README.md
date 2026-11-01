# Minimum Moves to Equal Array Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.

In one move, you can increment `n - 1` elements of the array by `1`.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

```

**Example 2:**

```
Input: nums = [1,1,1]
Output: 0

```

 

**Constraints:**

- n == nums.length
- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109
- The answer is guaranteed to fit in a 32-bit integer.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 30.38%)  
**Memory:** 31.7 MB (beats 99.75%)  
**Submitted:** 2026-11-01T05:17:53.843Z  

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int opr=0;
        for(int i=0;i<nums.size();i++){
            if(mini!=nums[i])opr+=nums[i]-mini;
        }
        return opr;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)