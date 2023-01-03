// https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 100, cur = 0;
        s += ' ';
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                cur = cur * 10 + ch - '0';
            }
            else if (ch == ' ' && isdigit(s[i-1])) {
                if ((pre == 100) || (pre < cur)) {
                    pre = cur;
                    cur = 0;
                }
                else if (pre >= cur) {
                    return false;
                }
            }
        }
        return true;
    }
};
