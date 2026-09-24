class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void bfs(int sr, int sc, vector<vector<int>>& image, int color,
             int inicol) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            image[sr][sc] = color;

            for (int i = 0; i < 4; i++) {
                int nrow = sr + drow[i];
                int ncol = sc + dcol[i];
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                    image[nrow][ncol] == inicol && image[nrow][ncol] != color) {
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int inicol = image[sr][sc];
        bfs(sr, sc, image, color, inicol);
        return image;
    }
};