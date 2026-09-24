class Solution {
public:
    bool iscycle(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(iscycle(it,graph,vis,pathvis)==true) return true;
            }
            else if(vis[it]==1 && pathvis[it]==1){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                iscycle(i,graph,vis,pathvis);
            }
            
        }
        vector<int>result;
        for(int i=0;i<v;i++){
            if(pathvis[i]==0){
                result.push_back(i);
            }
        }
        return result;
    }
};