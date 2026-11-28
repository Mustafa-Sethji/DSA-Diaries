# Word Search

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Original
C++
**Example 1:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

```

**Example 2:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

```

**Example 3:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

```

 

**Constraints:**

- m == board.length
- n = board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consists of only lowercase and uppercase English letters.

 

**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

## Solution

**Language:** C++  
**Runtime:** 508 ms (beats 34.20%)  
**Memory:** 11.7 MB (beats 20.30%)  
**Submitted:** 2026-11-28T10:57:59.064Z  

```cpp
class Solution {
public:
    vector<int>del_row={0,0,1,-1};
    vector<int>del_col={1,-1,0,0};
    int n,m;

    bool find(int r,int c,int s,vector<vector<char>>& board, string word){
        if(s==word.size())return true;
        for(int i=0;i<4;i++){
            int n_r=r+del_row[i];
            int n_c=c+del_col[i];
            if(n_r<m && n_r>=0 && n_c<n && n_c>=0 &&
             board[n_r][n_c]!='#' && board[n_r][n_c]==word[s]){
                char str=board[n_r][n_c];
                board[n_r][n_c]='#';

                if(find(n_r,n_c,s+1,board,word))return true;

                board[n_r][n_c]=str;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]) {
                    char str=board[i][j];
                    board[i][j]='#';
                    if(find(i,j,1,board,word))return true;
                    board[i][j]=str;
                }
            }
        }
        return false;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/word-search/)