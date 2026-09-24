class Solution {
    private:
    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        //{dist,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        distance[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return dist;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    int newdist=max(abs(heights[nrow][ncol]-heights[row][col]),dist);
                    if(newdist<distance[nrow][ncol]){
                        distance[nrow][ncol]=newdist;
                        pq.push({newdist,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};