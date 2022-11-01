// https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt_open = 0, cnt_close = 0;
        for (char ch: s) {
            if (ch == '(') {
                cnt_open += 1;
            }
            else {
                if (cnt_open > 0) {
                    cnt_open -= 1;
                }
                else {
                    cnt_close += 1;
                }
            }
        }
        int res = cnt_open + cnt_close;
        return res;
    }
};
