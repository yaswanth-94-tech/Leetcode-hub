#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // Custom struct to organize edge data cleanly
    struct Edge {
        int to;
        long long empty_cost;
        long long full_cost;
    };

public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        // Build the graph using an adjacency list
        vector<vector<Edge>> graph(n);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            long long cost = road[2];
            long long tax = road[3];
            
            graph[u].push_back({v, cost, cost * tax});
            graph[v].push_back({u, cost, cost * tax});
        }

        // Helper lambda to run Dijkstra's Algorithm from a given start node
        auto get_shortest_paths = [&](int start, bool is_full) {
            const long long INF = 1e18; // Large number representing infinity
            vector<long long> dist(n, INF);
            dist[start] = 0;
            
            // Min-heap storing pairs of {current_distance, node}
            priority_queue<pair<long long, int>, 
                           vector<pair<long long, int>>, 
                           greater<pair<long long, int>>> pq;
                           
            pq.push({0, start});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                // Skip processing if we've already found a strictly shorter path
                if (d > dist[u]) continue;

                for (const auto& edge : graph[u]) {
                    long long weight = is_full ? edge.full_cost : edge.empty_cost;
                    
                    // Relaxation step
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
            // 1. Compute shortest paths from i to all j (traveling empty)
            vector<long long> dist_empty = get_shortest_paths(i, false);
            
            // 2. Compute shortest paths from i to all j (traveling full)
            vector<long long> dist_full = get_shortest_paths(i, true);

            long long min_total_cost = 1e18;
            for (int j = 0; j < n; ++j) {
                // Total cost: Go to j empty + Return to i full + Buy apples at j
                long long total = dist_empty[j] + dist_full[j] + prices[j];
                if (total < min_total_cost) {
                    min_total_cost = total;
                }
            }
            
            // Cast back to int to match the required method signature
            ans[i] = static_cast<int>(min_total_cost);
        }

        return ans;
    }
};