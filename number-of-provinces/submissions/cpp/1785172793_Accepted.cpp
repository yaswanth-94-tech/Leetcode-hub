class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>ls){
        vis[node]=1;
        for(auto it:ls[node]){
            if(vis[it]==0){
                vis[it]=1;
                dfs(it,vis,ls);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> ls(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,vis,ls);
            }
        }
        return count;
    }
};