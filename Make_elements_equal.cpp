class Solution {
public:
    // we'll choose medain over mean because of it's robustness to outliers
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int M = 0;
        if(n % 2 == 0)
            M = floor((nums[n / 2 - 1] + nums[n / 2]) / 2);
        else
            M = nums[floor(n / 2)];  

        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - M);
        }

        return moves;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();