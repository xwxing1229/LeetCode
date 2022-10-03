// https://leetcode.cn/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a'] = cnt[ch - 'a'] + 1;
        }
        for (char ch: t) {
            cnt[ch - 'a'] = cnt[ch - 'a'] - 1;
            if (cnt[ch - 'a'] < 0) {
                return ch;
            }
        }
        return 'a';
    }
};
