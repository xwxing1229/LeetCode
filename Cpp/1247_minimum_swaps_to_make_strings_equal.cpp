// https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int s1_x = 0, s1_y = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') s1_x += 1;
                else s1_y += 1;
            }
        }

        int res = s1_x / 2 + s1_y / 2;
        int remain = s1_x % 2 + s1_y % 2;
        if (remain == 1) return -1;
        else if (remain == 0) return res;
        else return res + 2;
    }
};