// https://leetcode.cn/problems/count-asterisks/

class Solution {
public:
    int countAsterisks(string s) {
        int res = 0, inside = 0;
        for (char ch: s) {
            if (ch == '|') {
                inside = 1 - inside;
            }
            else if (ch == '*' && !inside) {
                res += 1;
            }
        }
        return res;
    }
};
