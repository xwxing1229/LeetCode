// https://leetcode.cn/problems/alternating-digit-sum/

class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, add = 1, digits = 0;
        while (n > 0) {
            res += add * (n % 10);
            n /= 10;
            add = -add;
            digits += 1;
        }
        if (digits % 2 == 0) {
            res = -res;
        }
        return res;
    }
};
