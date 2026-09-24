class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid,int n,int m) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> drow = {-1, 0, 1, 0};
            vector<int> dcol = {0, 1, 0, -1};
            for (int k=0;k<4;k++) {

                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
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
                    bfs(i, j, vis, grid,n,m);
                }
            }
        }
        return count;
    }
};