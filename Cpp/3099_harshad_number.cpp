// https://leetcode.cn/problems/harshad-number/

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int res = 0, num = x;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return x % res == 0 ? res : -1;
    }
};
