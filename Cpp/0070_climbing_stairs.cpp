// https://leetcode.cn/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int last = 1, last_last = 1;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            res = last + last_last;
            last_last = last;
            last = res;
        }
        return res;
    }
};
