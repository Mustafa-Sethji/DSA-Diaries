# Maximize Consecutive Elements in an Array After Modification

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a **0-indexed** array `nums` consisting of **positive** integers.

Initially, you can increase the value of **any** element in the array by **at most** `1`.

After that, you need to select **one or more** elements from the final array such that those elements are **consecutive** when sorted in increasing order. For example, the elements `[3, 4, 5]` are consecutive while `[3, 4, 6]` and `[1, 1, 2, 3]` are not.

Return *the **maximum** number of elements that you can select*.

 

Original
C++
**Example 1:**

```
Input: nums = [2,1,5,1,1]
Output: 3
Explanation: We can increase the elements at indices 0 and 3. The resulting array is nums = [3,1,5,2,1].
We select the elements [3,1,5,2,1] and we sort them to obtain [1,2,3], which are consecutive.
It can be shown that we cannot select more than 3 consecutive elements.
```

**Example 2:**

```
Input: nums = [1,4,7,10]
Output: 1
Explanation: The maximum consecutive elements that we can select is 1.

```

 

**Constraints:**

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 219 ms (beats 70.87%)  
**Memory:** 120.2 MB (beats 66.99%)  
**Submitted:** 2026-11-20T14:57:57.923Z  

```cpp
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i,int inc,vector<int>&nums){
        if(i>=n)return 0;
        if(dp[i][inc]!=-1)return dp[i][inc];

        int len=1;
        int currval=nums[i]+inc;
        int j=find_method(currval+1,nums,i+1);

        if(j!=-1)
            len=max(len,1+solve(j,0,nums));
        
        j=find_method(currval,nums,i+1);

        if(j!=-1)
            len=max(len,1+solve(j,1,nums));
        
        return dp[i][inc]=len;
    }

    int find_method(int x,vector<int>&nums,int start){
        int j=lower_bound(nums.begin()+start,nums.end(),x)-begin(nums);
        if(j<n && nums[j]==x)return j;
        return -1;
        
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        n=nums.size();
        int result=1;
        dp.assign(n,vector<int>(2,-1));

        for(int i=0;i<n;i++){
            result=max(result,max(solve(i,0,nums),solve(i,1,nums)));
        }
        
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/)