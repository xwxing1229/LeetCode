// https://leetcode.cn/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        int idx = 0, val = 0, scale = 1, len = 1;
        while (true) {
            // if (idx + 9 * scale * len <= n) {
            if ((n - idx) / 9. >= scale * len) {
                idx = idx + 9 * scale * len;
                val = val + 9 * scale;
                scale = scale * 10;
                len = len + 1;
            }
            else {
                break;
            }
        }

        int num = val + (n - idx) / len, rem = (n - idx) % len;
        if (rem != 0) {
            num = num + 1;
            for (int i = 0; i < len-rem; ++i) {
                num = num / 10;
            }
        }
        int res = num % 10;
        return res;
    }
};
