// https://leetcode.cn/problems/counting-bits/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if ((n > 0) && ((n & (n-1)) == 0) && ((n & 0b10101010101010101010101010101010) == 0)) {
            return true;
        }
        else {
            return false;
        }
    }
};
