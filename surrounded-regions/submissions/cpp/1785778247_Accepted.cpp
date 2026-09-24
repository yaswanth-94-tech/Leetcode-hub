class Solution {
public:
    int n, m;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void bfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0) {
                vis[i][0] = 1;
                bfs(i, 0, board, vis);
            }
            if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0) {
                vis[i][m - 1] = 1;
                bfs(i, m - 1, board, vis);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && vis[0][i] == 0) {
                vis[0][i] = 1;
                bfs(0, i, board, vis);
            }
            if (board[n - 1][i] == 'O' && vis[n - 1][i] == 0) {
                vis[n - 1][i] = 1;
                bfs(n - 1, i, board, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};