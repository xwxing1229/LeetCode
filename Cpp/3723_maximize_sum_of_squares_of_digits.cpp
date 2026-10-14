// https://leetcode.cn/problems/maximize-sum-of-squares-of-digits/

#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        if (num * 9 < sum) {
            return res;
        }
        res.reserve(num);
        for (int i = 9; i >= 1; --i) {
            int cnt = sum / i;
            if (cnt <= num) {
                res += string(cnt, '0'+i);
                num -= cnt;
                sum -= cnt * i;
                if (sum == 0) {
                    break;
                }
            }
        }
        res += string(num, '0');
        return res;
    }
};