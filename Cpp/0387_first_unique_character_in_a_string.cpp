// https://leetcode.cn/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a'] = cnt[ch - 'a'] + 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
