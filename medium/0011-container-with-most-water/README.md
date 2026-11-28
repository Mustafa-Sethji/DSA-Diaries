# Container With Most Water

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

 

Original
C++
**Example 1:**

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

```

**Example 2:**

```
Input: height = [1,1]
Output: 1

```

 

**Constraints:**

- n == height.length
- 2 <= n <= 105
- 0 <= height[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 62.8 MB (beats 80.81%)  
**Submitted:** 2026-11-28T09:27:25.707Z  

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int j=n-1,i=0;
        int ans=INT_MIN;
        while(i<j){
            int mini=min(height[i],height[j]);
            int area=mini*(j-i);
            ans=max(area,ans);
            if(height[i]<height[j])i++;
            else if(height[i]>height[j])j--;
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/container-with-most-water/)