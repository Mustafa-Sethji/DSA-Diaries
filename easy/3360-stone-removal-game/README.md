# Stone Removal Game

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Alice and Bob are playing a game where they take turns removing stones from a pile, with *Alice going first*.

- Alice starts by removing exactly 10 stones on her first turn.
- For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.

The player who cannot make a move loses the game.

Given a positive integer `n`, return `true` if Alice wins the game and `false` otherwise.

 

Original
C++
**Example 1:**

**Input:** n = 12

**Output:** true

**Explanation:**

- Alice removes 10 stones on her first turn, leaving 2 stones for Bob.
- Bob cannot remove 9 stones, so Alice wins.

**Example 2:**

**Input:** n = 1

**Output:** false

**Explanation:**

- Alice cannot remove 10 stones, so Alice loses.

 

**Constraints:**

- 1 <= n <= 50

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.7 MB (beats 72.34%)  
**Submitted:** 2026-11-26T10:55:49.901Z  

```cpp
class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        int remove=10;
        while(n>=remove){
            n-=remove;
            remove--;
        }
        if(remove%2==0)return false;
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stone-removal-game/)