// https://leetcode.cn/problems/distribute-money-to-maximum-children/

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) return -1;

        int res = money / 7, rem = money % 7;
        if (res > children) {
            res = children - 1;
        }
        else if (res == children) {
            if (rem != 0) {
                res -= 1;
            }
        }
        else {
            if (rem == 3 && children - res == 1) {
                res -= 1;
            }
        }
        return res;
    }
};