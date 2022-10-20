// https://leetcode.cn/problems/number-of-segments-in-a-string/

class Solution {
public:
    int countSegments(string s) {
        int res = 0, n = s.size();
        if (n == 0) {
            return res;
        }
        char pre = s[0];
        for (int i = 0; i < n; ++i) {
            if ((s[i] == ' ') && (pre != ' ')) {
                res += 1;
            }
            pre = s[i];
        }
        if (s[n-1] != ' ') {
            res += 1;
        }
        return res;
    }
};
