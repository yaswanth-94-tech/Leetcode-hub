class dsu {
public:
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findparent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node]);
    }

    void unionbysize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrows = 0;
        int maxcols = 0;
        for (auto it : stones) {
            maxrows = max(maxrows, it[0]);
            maxcols = max(maxcols, it[1]);
        }
        dsu ds(maxrows + maxcols + 2);
        unordered_map<int, int> stonenodes;
        for (auto it : stones) {
            int noderow = it[0];
            int nodecol = it[1] + maxrows + 1;
            ds.unionbysize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int count = 0;
        for (auto it : stonenodes) {
            if (ds.findparent(it.first) == it.first)
                count++;
        }
        int result = n - count;
        return result;
    }
};