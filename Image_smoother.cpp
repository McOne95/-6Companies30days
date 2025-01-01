class Solution {
    int M, N;
    // using bitmasking we can do it in-place
    // why 8 bits because pixel has value 0-255 so it needs only 8 bits
public:
    void filter(int i, int j, vector<vector<int>>& img) {
        int new_val = 0, count = 0;
        for(int x = i - 1; x <= i + 1; x++) {
            for(int y = j - 1; y <= j + 1; y++) {
                if(x < M && x >= 0 && y < N && y >= 0) {
                    count += 1;
                    new_val += (img[x][y] & 0xFF); // 0x11111111 extracting old value
                }
            }
        }

        new_val = floor(new_val / count);
        img[i][j] |= (new_val << 8); // adding new value in higher bits and old value lie in lower bits
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        M = img.size(), N = img[0].size();

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                filter(i, j, img);
            }
        }
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                img[i][j] >>= 8; // changing to new value
            }
        }

        return img;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
} ();