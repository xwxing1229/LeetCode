// https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/

class Solution {
public:
    string greatestLetter(string s) {
        string res;
        char tmp;
        vector<int> lower(26), upper(26);
        for (char ch: s) {
            if (islower(ch)) {
                if ((upper[ch - 'a']) && (toupper(ch) > tmp)) {
                    tmp = toupper(ch);
                }
                else {
                    lower[ch - 'a'] = 1;
                }
            }
            else {
                if ((lower[ch - 'A']) && (ch > tmp)) {
                    tmp = ch;
                }
                else {
                    upper[ch - 'A'] = 1;
                }
            }
        }
        if (isalpha(tmp)) {
            res += tmp;
        }
        return res;
    }
};
