// https://leetcode.cn/problems/count-commas-in-range/

#include <algorithm>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int digits = 0, num = n;
        while (num > 0) {
            num /= 10;
            digits += 1;
        }
        int res = 0, left = 1000;
        for (int d = 4; d <= digits; ++d) {
            int right = min(left * 10 - 1, n);
            res += right - left + 1;
            left *= 10;
        }
        return res;
    }
};