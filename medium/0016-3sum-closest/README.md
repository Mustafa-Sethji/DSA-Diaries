# 3Sum Closest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n` and an integer `target`.

Find three integers at **distinct indices** in `nums` such that the sum is **closest** to `target`.

Return the sum of the three integers.

You may assume that each input would have **exactly** one solution.

 

Original
C++
**Example 1:**

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```

**Example 2:**

```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

```

 

**Constraints:**

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -104 <= target <= 104

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 70.27%)  
**Memory:** 14.1 MB (beats 9.21%)  
**Submitted:** 2026-11-28T11:55:56.241Z  

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int close=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int current=abs(target-sum);
                if(close>current){
                    close=current;
                    ans=sum;
                }
                if(sum<target)j++;
                else k--;
            }
        } 
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/3sum-closest/)