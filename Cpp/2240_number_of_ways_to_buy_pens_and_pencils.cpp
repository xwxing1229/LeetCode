// https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        for (int i = total; i >= 0; i -= cost1) {
            res += i / cost2 + 1;
        }
        return res;
    }
};