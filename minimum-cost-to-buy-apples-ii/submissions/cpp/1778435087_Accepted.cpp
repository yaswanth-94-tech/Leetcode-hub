#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    struct Edge {
        int to;
        long long empty_cost;
        long long full_cost;
    };

public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<Edge>> graph(n);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            long long cost = road[2];
            long long tax = road[3];
            
            graph[u].push_back({v, cost, cost * tax});
            graph[v].push_back({u, cost, cost * tax});
        }

        auto get_shortest_paths = [&](int start, bool is_full) {
            const long long INF = 1e18;
            vector<long long> dist(n, INF);
            dist[start] = 0;
            
            priority_queue<pair<long long, int>, 
                           vector<pair<long long, int>>, 
                           greater<pair<long long, int>>> pq;
                           
            pq.push({0, start});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (const auto& edge : graph[u]) {
                    long long weight = is_full ? edge.full_cost : edge.empty_cost;
                    
                    if (dist[u] + weight < dist[edge.to]) {
                        dist[edge.to] = dist[u] + weight;
                        pq.push({dist[edge.to], edge.to});
                    }
                }
            }
            return dist;
        };

        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            vector<long long> dist_empty = get_shortest_paths(i, false);
            vector<long long> dist_full = get_shortest_paths(i, true);

            long long min_total_cost = 1e18;
            for (int j = 0; j < n; ++j) {
                long long total = dist_empty[j] + dist_full[j] + prices[j];
                if (total < min_total_cost) {
                    min_total_cost = total;
                }
            }
            
            ans[i] = static_cast<int>(min_total_cost);
        }

        return ans;
    }
};