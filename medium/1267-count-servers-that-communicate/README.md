# Count Servers that Communicate

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

**Example 2:**

```
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

```

**Example 3:**

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

```

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 1 <= m <= 250
- 1 <= n <= 250
- grid[i][j] == 0 or 1

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 16.73%)  
**Memory:** 29.1 MB (beats 12.81%)  
**Submitted:** 2026-11-08T04:44:19.296Z  

```cpp
class Solution {
public:
    vector<int>vis_row;
    vector<int>vis_col;
    int n,m;
    int dfs_counter(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(grid[r][c]==0) return 0;
        vis[r][c]=1;
        int cnt=1;
        if(!vis_col[c]){
            vis_col[c] = 1;
            for(int i=0;i<n;i++){
                if(i!=r && !vis[i][c] && grid[i][c]==1){
                    cnt+=dfs_counter(i,c,vis,grid);
                }
            }
        }

        if(!vis_row[r]){
            vis_row[r]=1;
            for(int i=0;i<m;i++){
                if(i!=c && !vis[r][i] && grid[r][i]==1){
                    cnt+=dfs_counter(r,i,vis,grid);
                }
            }
        }

        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis_row.assign(n,0);
        vis_col.assign(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int connected=dfs_counter(i,j,vis,grid);
                    if(connected>1)ans+=connected;
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-servers-that-communicate/)