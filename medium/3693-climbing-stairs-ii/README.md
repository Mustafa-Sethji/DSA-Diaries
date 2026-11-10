# Climbing Stairs II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are climbing a staircase with `n + 1` steps, numbered from 0 to `n`.

You are also given a **1-indexed** integer array `costs` of length `n`, where `costs[i]` is the cost of step `i`.

From step `i`, you can jump **only** to step `i + 1`, `i + 2`, or `i + 3`. The cost of jumping from step `i` to step `j` is defined as: `costs[j] + (j - i)2`

You start from step 0 with `cost = 0`.

Return the **minimum** total cost to reach step `n`.

 

Original
C++
**Example 1:**

**Input:**
int n = 4;
vector<int> costs = {1, 2, 3, 4};

**Output:** 13

**Explanation:**

One optimal path is `0 → 1 → 2 → 4`

Jump	Cost Calculation	Cost
0 → 1	`costs[1] + (1 - 0)2 = 1 + 1`	2
1 → 2	`costs[2] + (2 - 1)2 = 2 + 1`	3
2 → 4	`costs[4] + (4 - 2)2 = 4 + 4`	8

Thus, the minimum total cost is `2 + 3 + 8 = 13`

**Example 2:**

**Input:**
int n = 4;
vector<int> costs = {5, 1, 6, 2};

**Output:** 11

**Explanation:**

One optimal path is `0 → 2 → 4`

Jump	Cost Calculation	Cost
0 → 2	`costs[2] + (2 - 0)2 = 1 + 4`	5
2 → 4	`costs[4] + (4 - 2)2 = 2 + 4`	6

Thus, the minimum total cost is `5 + 6 = 11`

**Example 3:**

**Input:**
int n = 3;
vector<int> costs = {9, 8, 3};

**Output:** 12

**Explanation:**

The optimal path is `0 → 3` with total cost = `costs[3] + (3 - 0)2 = 3 + 9 = 12`

 

**Constraints:**

- 1 <= n == costs.length <= 105​​​​​​​
- 1 <= costs[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 49 ms (beats 15.32%)  
**Memory:** 185.6 MB (beats 22.70%)  
**Submitted:** 2026-11-10T17:02:01.531Z  

```cpp
//Approach-1 (Recursion + Memo)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> memo;

    int solve(int i, int n, vector<int>& costs) {
        if (i == n)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int cost = INT_MAX;

        int j = i + 1; 
        if(j <= n)                                 // jump of 1
            cost = solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i);

        j = i + 2;                                      // jump of 2
        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));

        j = i + 3;                                      // jump of 3
        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));

        return memo[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n + 1, -1);
        return solve(0, n, costs);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/climbing-stairs-ii/)