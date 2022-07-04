// https://leetcode.cn/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0, base = 5;
        while (base <= n) {
            int quo = n / base;
            res = res + quo;
            base = base * 5;
        }
        return res;
    }
};
