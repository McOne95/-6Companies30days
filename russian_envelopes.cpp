class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        auto lambda = [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(env.begin(), env.end(), lambda); // why descending h? to ensure no two same width and increasing h envelopes comes in LIS

        vector<int> h;
        for(auto it : env)
            h.push_back(it[1]);

        vector<int> LIS;
        for(int i = 0; i < h.size(); i++) { // we greedily take least h from same widht envelopes, only the smallest height matters because larger heights cannot contribute to a valid nesting sequence
            if(LIS.empty() || LIS.back() < h[i])
                LIS.push_back(h[i]);
            else {
                auto it = lower_bound(LIS.begin(), LIS.end(), h[i]);
                *it = h[i];
            }    
        }    

        return LIS.size();
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();