// https://leetcode.cn/problems/remove-letter-to-equalize-frequency/

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt_tmp(26, 0);
        for (char ch: word) {
            cnt_tmp[ch - 'a'] += 1;
        }
        vector<int> cnt;
        for (int c: cnt_tmp) {
            if (c > 0) cnt.push_back(c);
        }
        for (int i = 0; i < cnt.size(); ++i) {
            cnt[i] -= 1;
            unordered_set<int> s;
            for (int j = 0; j < cnt.size(); ++j) {
                if (cnt[j] > 0) {
                    s.insert(cnt[j]);
                }
            }
            if (s.size() == 1) return true;
            cnt[i] += 1;
        }
        return false;
    }
};
