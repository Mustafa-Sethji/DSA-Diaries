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