// https://leetcode.cn/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left = left >> 1;
            right = right >> 1;
            shift = shift + 1;
        }
        int res = left << shift;
        return res;
    }
};
