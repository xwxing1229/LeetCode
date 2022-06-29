// https://leetcode.cn/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        string word = "", res = "";
        s = ' ' + s;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (word.size() > 0) {
                    res = res + word + ' ';
                    word.clear();
                }
            }
            else {
                word = s[i] + word;
            }
        }
        res.pop_back();
        return res;
    }
};
