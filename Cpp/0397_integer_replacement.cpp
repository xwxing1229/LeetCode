// https://leetcode.cn/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
                res = res + 1;
            }
            else if (n % 4 == 1) {
                n = n / 2;
                res = res + 2;
            }
            else {
                if (n == 3) {
                    n = n / 2;
                    res = res + 2;
                }
                else {
                    n = n / 2 + 1;
                    res = res + 2;
                }
            }
        }
        return res;
    }
};
