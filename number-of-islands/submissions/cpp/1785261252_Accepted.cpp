class Solution {
public:
    void dfs(int row, int col, int n, int m,
             vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, n, m, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, n, m, vis, grid);
                }
            }
        }
        return count;
    }
};