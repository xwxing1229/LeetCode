// https://leetcode.cn/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch-'a'] += 1;
        }
        string res = "";
        for (char ch: order) {
            for (int i = 0; i < cnt[ch-'a']; ++i) {
                res += ch;
            }
            cnt[ch-'a'] = 0;
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < cnt[k]; ++i) {
                res += ('a' + k);
            }
        }
        return res;
    }
};
