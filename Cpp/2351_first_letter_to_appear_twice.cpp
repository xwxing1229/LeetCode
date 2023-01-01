// https://leetcode.cn/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> cnt(26);
        for (char ch: s) {
            if (cnt[ch-'a']) {
                return ch;
            }
            cnt[ch-'a'] = 1;
        }
        return '-';
    }
};