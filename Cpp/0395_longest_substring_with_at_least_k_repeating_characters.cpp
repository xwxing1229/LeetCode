// https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) {
            return 0;
        }

        int res = 0;
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch] = cnt[ch] + 1;
        }
        for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
            if (iter->second < k) {
                vector<string> sp = split(s, iter->first);
                for (string s_sub: sp) {
                    res = max(res, longestSubstring(s_sub, k));
                }
                return res;
            }
        }
        return s.size();
    }

private:
    vector<string> split(string s, char deli) {
        vector<string> res;
        string tmp;
        for (char ch: s) {
            if (ch == deli) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp = tmp + ch;
            }
        }
        if (s[s.size()-1] != deli) {
            res.push_back(tmp);
        }
        return res;
    }
};
