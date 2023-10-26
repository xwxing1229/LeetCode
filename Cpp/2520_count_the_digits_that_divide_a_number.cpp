// https://leetcode.cn/problems/count-the-digits-that-divide-a-number/

class Solution {
public:
    int countDigits(int num) {
        int res = 0, val = num;
        while (val > 0) {
            if (num % (val % 10) == 0) {
                res += 1;
            }
            val /= 10;
        }
        return res;
    }
};
