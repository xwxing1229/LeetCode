// https://leetcode.cn/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        // int res = 0;
        // while (num > 0) {
        //     while (num > 0) {
        //         res = res + num % 10;
        //         num = num / 10;
        //     }
        //     if (res > 9) {
        //         num = res;
        //         res = 0;
        //     }
        // }
        // return res;

        // A mathematical method.
        if (num == 0) {
            return 0;
        }

        int res = num % 9;
        if (res == 0) {
            res = 9;
        }
        return res;
    }
};
