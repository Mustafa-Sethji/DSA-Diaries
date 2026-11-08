class Solution {
public:
    vector<int>d_row={1,-1,0,0};
    vector<int>d_col={0,0,1,-1};
    int n,m;
    int dfs_counter(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(grid[r][c]==0) return 0;
        vis[r][c]=1;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(i!=r && !vis[i][c] && grid[i][c]==1){
                cnt+=dfs_counter(i,c,vis,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(i!=c && !vis[r][i] && grid[r][i]==1){
                cnt+=dfs_counter(r,i,vis,grid);
            }
        }
        // for(int i=0;i<4;i++){
        //     int n_r=r+d_row[i];
        //     int n_c=c+d_col[i];
        //     if(n_r<n && n_r>=0 && n_c<m && n_c>=0 && !vis[n_r][n_c]){
        //         cnt+=dfs_counter(n_r,n_c,vis,grid);
        //     }
        // }
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
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