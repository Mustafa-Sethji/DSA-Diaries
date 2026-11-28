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