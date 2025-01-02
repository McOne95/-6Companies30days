#define ll long long

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        vector<vector<ll>> dist(26, vector<ll> (26, INT_MAX));
        for(int i = 0; i < n; i++)
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]); // multiple transformation may exist
        for(int i = 0; i < 26; i++) 
            dist[i][i] = 0;

        for(int v = 0; v < 26; v++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][v] == INT_MAX || dist[v][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]); // why long long? int overflow will occur   
                }
            }
        }

        ll minCost = 0; 
        int m = source.length();   
        for(int i = 0; i < m; i++) {
            if(dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                return -1;
            minCost += dist[source[i] - 'a'][target[i] - 'a'];
        }

        return minCost;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();