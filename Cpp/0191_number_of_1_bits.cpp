// https://leetcode.cn/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (n & 1) + res;
            n = n >> 1;
        }
        return res;
    }
};
