// https://leetcode.cn/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        s = " " + s + " ";
        int res = 0, tmp = 0;
        for (int i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (c != ' ') {
                tmp = tmp + 1;
            }
            else if (s[i-1] != ' ') {
                res = tmp;
                tmp = 0;
            }
        }
        return res;
    }
};
