class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newrow=i+drow[k];
            int newcol=j+dcol[k];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]==0 && grid[newrow][newcol]=='1'){
                dfs(newrow,newcol,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return count;
    }
};