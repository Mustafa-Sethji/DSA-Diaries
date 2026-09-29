# Check if There Is a Valid Parentheses String Path

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A parentheses string is a **non-empty** string consisting only of `'('` and `')'`. It is **valid** if **any** of the following conditions is **true**:

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A **valid parentheses string path** in the grid is a path satisfying **all** of the following conditions:

- The path starts from the upper left cell (0, 0).
- The path ends at the bottom-right cell (m - 1, n - 1).
- The path only ever moves down or right.
- The resulting parentheses string formed by the path is valid.

Return `true` *if there exists a **valid parentheses string path** in the grid.* Otherwise, return `false`.

 

**Example 1:**

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

```

**Example 2:**

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

```

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- grid[i][j] is either '(' or ')'.

## Solution

**Language:** C++  
**Runtime:** 175 ms (beats 42.63%)  
**Memory:** 30.1 MB (beats 50.20%)  
**Submitted:** 2026-09-29T04:55:42.737Z  

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance <= m + n; balance++) {

                    if (!dp[i][j][balance])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int newBalance = balance;

                        if (grid[i + 1][j] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0)
                            dp[i + 1][j][newBalance] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBalance = balance;

                        if (grid[i][j + 1] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0)
                            dp[i][j + 1][newBalance] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)