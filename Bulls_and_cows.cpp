class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls = 0, cows = 0;

        vector<int> count_secret(10, 0), count_guess(10, 0);

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } 
            
            else {
                count_secret[secret[i] - '0']++;
                count_guess[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += min(count_secret[i], count_guess[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
