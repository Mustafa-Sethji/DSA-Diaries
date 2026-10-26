# Count Islands With Total Value Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `grid` and a positive integer `k`. An **island** is a group of **positive** integers (representing land) that are **4-directionally** connected (horizontally or vertically).

The **total value** of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value **divisible by** `k`.

 

**Example 1:**

**Input:** grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

**Output:** 2

**Explanation:**

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

**Example 2:**

**Input:** grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

**Output:** 6

**Explanation:**

The grid contains six islands, each with a total value that is divisible by 3.

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 0 <= grid[i][j] <= 106
- 1 <= k <= 106

## Solution

**Language:** C++  
**Runtime:** 989 ms (beats 5.14%)  
**Memory:** 105.6 MB (beats 37.69%)  
**Submitted:** 2026-10-26T18:06:57.072Z  

```cpp
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        function<long long(int, int)> dfs = [&](int i, int j) -> long long {
            if (i < 0 || i >= m || j < 0 || j >= n ||
                grid[i][j] == 0) {
                return 0;
            }

            long long sum = grid[i][j];
            grid[i][j] = 0; // Mark visited

            sum += dfs(i + 1, j);
            sum += dfs(i - 1, j);
            sum += dfs(i, j + 1);
            sum += dfs(i, j - 1);

            return sum;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)