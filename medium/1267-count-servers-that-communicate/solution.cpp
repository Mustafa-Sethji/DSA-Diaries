class Solution {
public:
    vector<int>d_row={1,-1,0,0};
    vector<int>d_col={0,0,1,-1};
    vector<int>vis_row;
    vector<int>vis_col;
    int n,m;
    int dfs_counter(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(grid[r][c]==0) return 0;
        vis[r][c]=1;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(!vis_row[r] && i!=r && !vis[i][c] && grid[i][c]==1){
                cnt+=dfs_counter(i,c,vis,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis_col[c] && i!=c && !vis[r][i] && grid[r][i]==1){
                cnt+=dfs_counter(r,i,vis,grid);
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