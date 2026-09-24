class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(int)1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto road:roads){
            int first=road[0];
            int second=road[1];
            int wt=road[2];
            adj[first].push_back({second,wt});
            adj[second].push_back({first,wt});
        }
        vector<long long>distance(n,LLONG_MAX);
        vector<int>ways(n,0);
        distance[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        //{dist,node};
        pq.push({0,0});
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist>distance[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgewt=it.second;
                if(dist+edgewt<distance[adjnode]){
                    distance[adjnode]=dist+edgewt;
                    pq.push({distance[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dist+edgewt==distance[adjnode]){
                    ways[adjnode]=(ways[node]+ways[adjnode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};