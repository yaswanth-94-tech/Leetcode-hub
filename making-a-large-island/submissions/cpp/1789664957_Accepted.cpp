
vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
class dsu {
public:
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findparent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findparent(parent[n]);
    }
    void unionbysize(int n, int m) {
        int pn = findparent(n);
        int pm = findparent(m);
        if (pn == pm)
            return;
        else {
            if (size[pn] < size[pm]) {
                parent[pn] = pm;
                size[pm] += size[pn];
            } else {
                parent[pm] = pn;
                size[pn] += size[pm];
            }
        }
    }
};

class Solution {
public:
    bool isvalid(int nrow, int ncol, int n) {
        return nrow < n && nrow >= 0 && ncol < n && ncol >= 0;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        dsu ds(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                else if (grid[row][col] == 1) {
                    for (int i = 0; i < 4; i++) {
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];
                        if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            int node = row * n + col;
                            int adjnode = nrow * n + ncol;
                            ds.unionbysize(node, adjnode);
                        }
                    }
                }
            }
        }

        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                else if (grid[row][col] == 0) {
                    set<int> components;
                    for (int i = 0; i < 4; i++) {
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];
                        if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                            int adjnode = nrow * n + ncol;
                            components.insert(ds.findparent(adjnode));
                        }
                    }
                    int sizetotal = 0;
                    for (auto it : components) {
                        sizetotal = sizetotal + ds.size[it];
                    }
                    mx = max(mx, sizetotal + 1);
                }
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    mx = max(mx, ds.size[ds.findparent(row * n + col)]);
                }
            }
        }
        return mx;
    }
};