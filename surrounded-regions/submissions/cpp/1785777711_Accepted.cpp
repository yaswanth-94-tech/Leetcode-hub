class Solution {
public:
    int n, m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (nrow <n && nrow>=0 && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0)
                dfs(i, 0, board, vis);
            if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0)
                dfs(i, m - 1, board, vis);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && vis[0][i] == 0)
                dfs(0, i, board, vis);
            if (board[n - 1][i] == 'O' && vis[n - 1][i] == 0)
                dfs(n - 1, i, board, vis);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};