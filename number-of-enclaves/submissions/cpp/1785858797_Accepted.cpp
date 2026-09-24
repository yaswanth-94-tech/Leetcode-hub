class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    int n, m;
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
        vis[row][col] = 1;
        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, vis, grid);
            }
            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) {
                dfs(i, m - 1, vis, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && vis[0][i] == 0) {

                dfs(0, i, vis, grid);
            }
            if (grid[n - 1][i] == 1 && vis[n - 1][i] == 0) {

                dfs(n - 1, i, vis, grid);
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    result++;
                }
            }
        }
        return result;
    }
};