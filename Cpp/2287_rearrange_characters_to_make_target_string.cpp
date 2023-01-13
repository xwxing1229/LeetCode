// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> require;
        for (char ch: target) {
            require[ch] += 1;
        }
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch-'a'] += 1;
        }
        int res = s.size() / target.size();
        for (auto iter = require.begin(); iter != require.end(); ++iter) {
            int tmp = cnt[iter->first-'a'] / iter->second;
            if (res > tmp) {
                res = tmp;
            }
        }
        return res;
    }
};
