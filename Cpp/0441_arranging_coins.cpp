// https://leetcode.cn/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        int res = (sqrt((long)8*n + 1) - 1) / 2;
        return res;
    }
};
