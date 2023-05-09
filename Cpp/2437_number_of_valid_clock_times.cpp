// https://leetcode.cn/problems/number-of-valid-clock-times/

class Solution {
public:
    int countTime(string time) {
        int res = 0;
        if (time[0] == '?') {
            if (time[1] == '?') {
                res = 24;
            }
            else {
                for (int i = 0; i < 3; ++i) {
                    if (i * 10 + time[1] - '0' < 24) {
                        res += 1;
                    }
                }
            }
        }
        else {
            if (time[1] == '?') {
                for (int i = 0; i < 10; ++i) {
                    if ((time[0] - '0') * 10 + i < 24) {
                        res += 1;
                    }
                }
            }
            else {
                res = 1;
            }
        }
        if (time[3] == '?') {
            res *= 6;
        }
        if (time[4] == '?') {
            res *= 10;
        }
        return res;
    }
};