// https://leetcode.cn/problems/pass-the-pillow/

class Solution {
public:
    int passThePillow(int n, int time) {
        int rem = time % (n+n-2);
        int res = 1 + rem;
        if (rem >= n) {
            res = n + n - 1 - rem;
        }
        return res;
    }
};