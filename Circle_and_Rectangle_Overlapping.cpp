class Solution {
public:
    // todo : Clamping 
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x_closest = max(x1, min(x2, xc)); // min - pt does not exceed the right boundary and max - pt does not preceed the left boundary
        int y_closest = max(y1, min(y2, yc));

        int x_delta = xc - x_closest;
        int y_delta = yc - y_closest;

        return x_delta * x_delta + y_delta * y_delta <= r * r;
    }
};

auto fastio = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
} ();