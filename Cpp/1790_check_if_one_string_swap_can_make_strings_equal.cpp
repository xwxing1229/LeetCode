// https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0, doSwap = 0;
        char tmp1 = '0', tmp2 = '0';
        for (int i = 0; i < s1.size(); ++i) {
            char ch1 = s1[i], ch2 = s2[i];
            if (ch1 != ch2) {
                if ((ch1 == tmp2) && (ch2 == tmp1)) {
                    cnt = cnt - 1;
                    doSwap = 1;
                    tmp1 = '0';
                    tmp2 = '0';
                }
                else {
                    cnt = cnt + 1;
                    tmp1 = ch1;
                    tmp2 = ch2;
                }

                if (((doSwap > 0) && (cnt > 0)) || (cnt > 1)) {
                    return false;
                }
            }
        }
        if (cnt > 0) {
            return false;
        }
        else {
            return true;
        }
    }
};
