#define ll long long
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>> dist(n, vector<ll> (n, INT_MAX));

        for(auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(int t = 0; t < n; t++) { // via
            for(int u = 0; u < n; u++) { // from
                for(int v = 0; v < n; v++) { // to
                    if(dist[u][t] == INT_MAX || dist[t][v] == INT_MAX) 
                        continue;
                    dist[u][v] = min(dist[u][v], dist[u][t] + dist[t][v]);    
                }
            }
        }

        int val = n, city = -1;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }

            if(count <= val) {
                val = count;
                city = max(city, i); // because we need city with greatest number
            }
        }

        return city;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();