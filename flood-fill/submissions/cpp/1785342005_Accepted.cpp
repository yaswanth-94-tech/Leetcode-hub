class Solution {
public:
    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int inicol){
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && image[nrow][ncol]==inicol && image[nrow][ncol]!=color){
                dfs(nrow,ncol,image,color,inicol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicol=image[sr][sc];
        dfs(sr,sc,image,color,inicol);
        return image;
    }
};