class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1, 1e9);
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto time : times) {
            int first = time[0];
            int second = time[1];
            int weight = time[2];
            adj[first].push_back({second, weight});
        }
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, k});
        while (!q.empty()) {
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            for(auto it:adj[node]){
                int nextnode=it.first;
                int weight=it.second;
                if(dis+weight<distance[nextnode]){
                    distance[nextnode]=dis+weight;
                    q.push({distance[nextnode],nextnode});
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==1e9){
                return -1;
            }
            else{
                sum=max(sum,distance[i]);
            }
        }
        return sum;
    }
};