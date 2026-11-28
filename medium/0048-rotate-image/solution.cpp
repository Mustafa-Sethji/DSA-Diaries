class Solution {
public:
    int n,m;
    void transpose(vector<vector<int>>& G){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i<j){
                    int temp=G[i][j];
                    G[i][j]=G[j][i];
                    G[j][i]=temp;
                }
            }
        }
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        transpose(matrix);
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};