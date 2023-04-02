// https://leetcode.cn/problems/perfect-number/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int s = -num;
        for (int i = 1; i <= (int)sqrt(num); ++i) {
            if (num % i == 0) {
                s += i;
                if (i != num / i) {
                    s += (num / i);
                }
            }
        }
        return s == num ? true: false;
    }
};
