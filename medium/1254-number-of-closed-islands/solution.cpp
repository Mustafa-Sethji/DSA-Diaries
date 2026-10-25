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