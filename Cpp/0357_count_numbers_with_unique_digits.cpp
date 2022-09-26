// https://leetcode.cn/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = 9;
            for (int j = 0; j < i; ++j) {
                tmp = tmp * (9-j);
            }
            res = res + tmp;
        }
        return res;
    }
};
