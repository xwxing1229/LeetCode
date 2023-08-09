// https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, s = 0;
        while (n > 0) {
            int num = n % 10;
            prod *= num;
            s += num;
            n /= 10;
        }
        return prod - s;
    }
};