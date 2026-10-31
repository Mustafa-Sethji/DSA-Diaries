
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
