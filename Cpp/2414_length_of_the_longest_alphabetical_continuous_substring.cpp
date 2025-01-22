// https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/

class Solution {
public:
    int longestContinuousSubstring(string s) {
        unordered_map<char, char> table;
        for (int i = 0; i < 26; ++i) {
            table['a'+i] = 'a'+i+1;
        }
        int res = 0, tmp = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (table[s[i-1]] == s[i]) {
                tmp += 1;
            }
            else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
        return res;
    }
};
