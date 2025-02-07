class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int dirs[2][5] = {{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}};
        auto check = [&](int i, int sx, int sy, int bx, int by) {
            for (int d = 0; d < 4; ++d) {
                for (int k = 1; k < 8; ++k) {
                    int x = sx + dirs[i][d] * k;
                    int y = sy + dirs[i][d + 1] * k;
                    if (x < 1 || x > 8 || y < 1 || y > 8 || (x == bx && y == by)) {
                        break;
                    }
                    if (x == e && y == f) {
                        return true;
                    }
                }
            }
            return false;
        };
        return check(0, a, b, c, d) || check(1, c, d, a, b) ? 1 : 2;
    }
};