// https://leetcode.cn/problems/smallest-divisible-digit-product-i/

class Solution {
public:
    int smallestNumber(int n, int t) {
        auto valid = [t](int num) {
            int prod = 1;
            while (num > 0) {
                prod *= (num % 10);
                num /= 10;
            }
            return prod % t == 0;
        };

        int num = n;
        while (num >= n) {
            if (valid(num)) return num;
            num += 1;
        }
        return -1;
    }
};