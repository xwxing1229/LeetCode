// https://leetcode.cn/problems/minimum-moves-to-convert-string/

class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.size();
        int res = 0;
        while (i < n) {
            if (s[i] == 'X') {
                res += 1;
                i += 3;
            }
            else {
                i += 1;
            }
        }
        return res;
    }
};
