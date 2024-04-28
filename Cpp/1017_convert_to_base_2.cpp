// https://leetcode.cn/problems/convert-to-base-2/

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return (string)"0";

        string res;
        while (n != 0) {
            int mod = n % (-2);
            if (mod == -1) {
                mod = 1;
            }
            n = (n - mod) / (-2);
            res += '0' + mod;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
