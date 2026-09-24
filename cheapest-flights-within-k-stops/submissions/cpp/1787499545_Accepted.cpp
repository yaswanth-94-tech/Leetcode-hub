class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int first=it[0];
            int second=it[1];
            int price=it[2];
            adj[first].push_back({second,price});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>distance(n,1e9);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            if(k<stops) continue;
            for(auto nd:adj[node]){
                auto it3=nd;
                auto adjnode=it3.first;
                auto adjdist=it3.second;
                if(stops<=k && dist+adjdist<distance[adjnode]){
                    distance[adjnode]=dist+adjdist;
                    q.push({stops+1,{adjnode,distance[adjnode]}});
                }
            }
        }
        if(distance[dst]==1e9)return -1;
        else return distance[dst];    
    }
};