# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An *island* is a maximal 4-directionally connected group of `0s` and a *closed island* is an island **totally** (all left, top, right, bottom) surrounded by `1s.`

Return the number of *closed islands*.

 

**Example 1:**

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

**Example 2:**

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

**Example 3:**

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

**Constraints:**

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 47.42%)  
**Memory:** 13.8 MB (beats 50.98%)  
**Submitted:** 2026-10-25T06:43:36.475Z  

```cpp
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> vis;
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(i>=n || i<0 || j>=m || j<0)return false;
        if(grid[i][j]==1)return true;
        grid[i][j]=1;

        bool top=dfs(i-1,j,grid,vis);
        bool right=dfs(i,j+1,grid,vis);
        bool down=dfs(i+1,j,grid,vis);
        bool left=dfs(i,j-1,grid,vis);

        return (top && left && right && down);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int island=0;
        vis.assign(n,vector<int>(m,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0 && dfs(i,j,grid,vis)) island++;
            }
        }
        return island;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)