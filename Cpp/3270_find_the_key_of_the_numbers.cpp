// https://leetcode.cn/problems/find-the-key-of-the-numbers/

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int res = 0, pow10 = 1;
        for (int i = 0; i < 4; ++i) {
            res += min(min(num1%10, num2%10), num3%10) * pow10;
            pow10 *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return res;
    }
};
