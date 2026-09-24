class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<rowShift.size();i++){
            if(rowShift[i]==0) continue;
            rowShift[i]=rowShift[i]%n;
            reverse(grid[i].begin(),grid[i].begin()+rowShift[i]);
            reverse(grid[i].begin()+rowShift[i],grid[i].end());
            reverse(grid[i].begin(),grid[i].end());
        }
        for(int j=0;j<colShift.size();j++){
            if(colShift[j]==0) continue;
            vector<int>col(n);
            for(int i=0;i<n;i++) col[i]=grid[i][j];
            for(int i=0;i<n;i++) grid[i][j]=col[(i+colShift[j])%n];
        }
        return grid;
    }
};