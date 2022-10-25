// https://leetcode.cn/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int start = 0, pre = -1;
        for (int i = 0; i < chars.size(); ++i) {
            if ((i == chars.size()-1) || (chars[i] != chars[i+1])) {
                chars[start] = chars[i];

                int cnt = i - pre, digits = 0;
                if (cnt > 1) {
                    while (cnt > 0) {
                        digits += 1;
                        chars[start + digits] = (char) ('0' + cnt % 10);
                        cnt = cnt / 10;
                    }
                    // Reverse.
                    for (int j = 1; j < digits/2+1; ++j) {
                        int tmp = chars[start + j];
                        chars[start + j] = chars[start + digits + 1 - j];
                        chars[start + digits + 1 - j] = tmp;
                    }
                }
                res += (1 + digits);
                start += (1 + digits);
                pre = i;
            }
        }
        return res;
    }
};
