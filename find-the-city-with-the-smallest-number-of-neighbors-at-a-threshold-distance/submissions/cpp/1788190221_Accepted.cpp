class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distancethreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            distance[from][to] = wt;
            distance[to][from] = wt;
        }
        for(int i=0;i<n;i++){
            distance[i][i]=0;
        }
        // floyd warshall algo
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] == 1e9 || distance[k][j] == 1e9)
                        continue;

                    distance[i][j] =
                        min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }



        int countcity=n;
        int cityno=-1;
        for(int city=0;city<n;city++){
            int count=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(distance[city][adjcity]<=distancethreshold) count++;
            }
            if(count<=countcity){
                countcity=count;
                cityno=city;
            }
        }
        return cityno;
    }
};