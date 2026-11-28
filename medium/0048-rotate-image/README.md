# Rotate Image

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

 

Original
C++
**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

```

**Example 2:**

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

```

 

**Constraints:**

- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.1 MB (beats 78.34%)  
**Submitted:** 2026-11-28T09:35:14.094Z  

```cpp
class Solution {
public:
    int n,m;
    void transpose(vector<vector<int>>& G){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i<j){
                    int temp=G[i][j];
                    G[i][j]=G[j][i];
                    G[j][i]=temp;
                }
            }
        }
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        transpose(matrix);
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotate-image/)