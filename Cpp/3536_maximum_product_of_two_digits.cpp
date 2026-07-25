// https://leetcode.cn/problems/maximum-product-of-two-digits/

class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while (n > 0) {
            int num = n % 10;
            n /= 10;
            if (num >= mx1) {
                mx2 = mx1;
                mx1 = num;
            }
            else if (num > mx2) {
                mx2 = num;
            }
        }
        return mx1 * mx2;
    }
};