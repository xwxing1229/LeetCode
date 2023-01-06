// https://leetcode.cn/problems/count-integers-with-even-digit-sum/

class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; ++i) {
            int s = 0, n = i;
            while (n) {
                s += n % 10;
                n /= 10;
            }
            if (s % 2 == 0) {
                res += 1;
            }
        }
        return res;
    }
};
