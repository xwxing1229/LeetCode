// https://leetcode.cn/problems/minimum-moves-to-capture-the-queen/
       
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e) {
            if (a == c && check(b, d, f)) return 2;
            return 1;
        }
        if (b == f) {
            if (b == d && check(a, c, e)) return 2;
            return 1;
        }
        if (c - d == e - f) {
            if (c - d == a - b && check(c, a, e)) return 2;
            return 1;
        }
        if (c + d == e + f) {
            if (c + d == a + b && check(c, a, e)) return 2;
            return 1;
        }
        return 2;
    }

    bool check(int x1, int x2, int x3) {
        return (x1 < x2 && x2 < x3) || (x1 > x2 && x2 > x3);
    }
};
