# Maximum Number of Items From Sale I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D integer array `items`, where `items[i] = [factori, pricei]` represents the `ith` item. You are also given an integer `budget`.

There are unlimited copies of each item available for purchase.You may buy any number of copies of any items such that the total cost of the purchased copies is at most `budget`.

After buying items, you may receive free copies according to the following rules:

- For each item i that you bought at least one copy of, you receive one free copy of every item j such that j != i and factori divides factorj.
- Buying multiple copies of the same item i does not give additional free copies through item i.
- The same item j can be received multiple times for free if it is received from purchases of different item types.

Return the **maximum total number of item copies** you can obtain, including both purchased copies and free copies, while spending at most `budget` on purchased items.

 

Original
C++
**Example 1:**

**Input:** items = [[6,2],[2,6],[3,4]], budget = 9

**Output:** 4

**Explanation:**

- You can buy 2 copies of item 0 and 1 copy of item 2 for a total cost of 2 * 2 + 4 = 8, which is not greater than budget = 9.
- Buying item 2 gives 1 free copy of item 0, because factor2 = 3 divides factor0 = 6.
- You leave with 3 purchased copies and 1 free copy, for a total of 4 item copies.

**Example 2:**

**Input:** items = [[2,4],[3,2],[4,1],[6,4],[12,4]], budget = 8

**Output:** 10

**Explanation:**

- You can buy 1 copy of item 0, 1 copy of item 1, and 2 copies of item 2 for a total cost of 4 + 2 + 2 * 1 = 8.
- Buying item 0 gives 1 free copy of items 2, 3, and 4.
- Buying item 1 gives 1 free copy of items 3 and 4.
- Buying item 2 gives 1 free copy of item 4.
- Thus, you receive 6 free copies. You leave with 4 purchased copies and 6 free copies, for a total of 10 item copies.

 

**Constraints:**

- 1 <= items.length <= 1000
- items[i] = [factori, pricei]
- 1 <= factori, pricei <= 1500
- 1 <= budget <= 1500

## Solution

**Language:** C++  
**Runtime:** 305 ms (beats 37.50%)  
**Memory:** 132.9 MB (beats 17.04%)  
**Submitted:** 2026-11-27T14:57:54.462Z  

```cpp
class Solution {
public:
    vector<int>precompute;
    vector<vector<int>>dp;
    int min_price;
    int n;
    int solve(int i,vector<vector<int>>& item,int budget){
        if(budget==0)return 0;
        if(i==n)return budget/min_price;

        if(dp[i][budget]!=-1)return dp[i][budget];

        int price=item[i][1];
        int buy=0;

        if(price<=budget){
            buy=1+precompute[i]+solve(i+1,item,budget-price);
        }

        int skip=solve(i+1,item,budget);

        return dp[i][budget]=max(buy,skip);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        precompute.assign(n,0);
        min_price=INT_MAX;
        
        for(int i=0;i<n;i++){
            min_price = min(min_price, items[i][1]);
            int fac_i=items[i][0];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int fac_j=items[j][0];
                if(fac_j%fac_i==0)precompute[i]++;
            }
        }

        dp.assign(n+1,vector<int>(budget+1,-1));

        return solve(0,items,budget);

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-items-from-sale-i/)