# Twisted Mirror Path Count

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` binary grid `grid` where:

- grid[i][j] == 0 represents an empty cell, and
- grid[i][j] == 1 represents a mirror.

A robot starts at the top-left corner of the grid `(0, 0)` and wants to reach the bottom-right corner `(m - 1, n - 1)`. It can move only **right** or **down**. If the robot attempts to move into a mirror cell, it is **reflected** before entering that cell:

- If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.
- If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the mirror.

If this reflection would cause the robot to move outside the `grid` boundaries, the path is considered invalid and should not be counted.

Return the number of unique valid paths from `(0, 0)` to `(m - 1, n - 1)`.

Since the answer may be very large, return it **modulo** `109 + 7`.

**Note**: If a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror: if it entered while moving right, it will be turned down; if it entered while moving down, it will be turned right. This process will continue until either the last cell is reached, the robot moves out of bounds or the robot moves to a non-mirror cell.

 

**Example 1:**

**Input:** grid = [[0,1,0],[0,0,1],[1,0,0]]

**Output:** 5

**Explanation:**

Number	Full Path
1	(0, 0) → (0, 1) [M] → (1, 1) → (1, 2) [M] → (2, 2)
2	(0, 0) → (0, 1) [M] → (1, 1) → (2, 1) → (2, 2)
3	(0, 0) → (1, 0) → (1, 1) → (1, 2) [M] → (2, 2)
4	(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2)
5	(0, 0) → (1, 0) → (2, 0) [M] → (2, 1) → (2, 2)
- [M] indicates the robot attempted to enter a mirror cell and instead reflected.

**Example 2:**

**Input:** grid = [[0,0],[0,0]]

**Output:** 2

**Explanation:**

Number	Full Path
1	(0, 0) → (0, 1) → (1, 1)
2	(0, 0) → (1, 0) → (1, 1)

**Example 3:**

**Input:** grid = [[0,1,1],[1,1,0]]

**Output:** 1

**Explanation:**

Number	Full Path
1	(0, 0) → (0, 1) [M] → (1, 1) [M] → (1, 2)
`(0, 0) → (1, 0) [M] → (1, 1) [M] → (2, 1)` goes out of bounds, so it is invalid.

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 500
- grid[i][j] is either 0 or 1.
- grid[0][0] == grid[m - 1][n - 1] == 0

## Solution

**Language:** C++  
**Runtime:** 1424 ms (beats 5.00%)  
**Memory:** 489.4 MB (beats 21.67%)  
**Submitted:** 2026-10-31T14:18:45.441Z  

```cpp

class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    //from UP=1 
    //form LEFT=0

    int solve(int i, int j, int dir, vector<vector<int>>& grid) {
        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j][dir]!=-1)return dp[i][j][dir];

        int total=0;

        if(grid[i][j]==1){
            if(dir==1) total=solve(i,j+1,0,grid)%MOD;
            else total=solve(i+1,j,1,grid)%MOD;
        }
        else{
            total+=solve(i,j+1,0,grid)%MOD;
            total+=solve(i+1,j,1,grid)%MOD;
        }

        return dp[i][j][dir]=total;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m,vector<vector<int>>(n, vector<int>(2,-1)));

        // Start from (0,0), direction doesn't matter
        return solve(0, 0, 0, grid)  % MOD;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/twisted-mirror-path-count/)