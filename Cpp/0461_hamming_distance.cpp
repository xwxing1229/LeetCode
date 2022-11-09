// https://leetcode.cn/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z > 0) {
            res += (z & 1);
            z = (z >> 1);
        }
        return res;
    }
};
