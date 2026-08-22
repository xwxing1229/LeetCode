// https://leetcode.cn/problems/check-divisibility-by-digit-sum-and-product/

class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1, num = n;
        while (num > 0) {
            int x = num % 10;
            num /= 10;
            s += x;
            p *= x;
        }
        return n % (s + p) == 0;
    }
};