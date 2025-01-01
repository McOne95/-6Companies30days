class Solution {
public:
    // Josephus problem
    int findTheWinner(int n, int k) {
        int winner = 0;

        // bottom up of recursive approach
        for(int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }

        return winner + 1;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();